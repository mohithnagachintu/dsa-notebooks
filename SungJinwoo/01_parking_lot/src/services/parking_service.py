from datetime import datetime
from typing import Dict, List, Optional

from domain import ParkingSpot, Ticket, Vehicle
from enums import SIZE_ORDER, VehicleSize


class ParkingManager:
    def __init__(
        self,
        available_spots: Dict[VehicleSize, List[ParkingSpot]],
        plate_to_spot_mapping: Optional[Dict[str, ParkingSpot]] = None,
    ) -> None:
        self.available_spots = available_spots
        self.plate_to_spot_mapping = plate_to_spot_mapping or {}
        self.plate_to_ticket_mapping: Dict[str, Ticket] = {}

    def find_spot_for_vehicle(self, vehicle: Vehicle) -> Optional[ParkingSpot]:
        vehicle_size = vehicle.get_size()
        start_index = SIZE_ORDER.index(vehicle_size)
        for size in SIZE_ORDER[start_index:]:
            for spot in self.available_spots.get(size, []):
                if spot.is_available():
                    return spot
        return None

    def can_park(self, vehicle: Vehicle) -> bool:
        plate = vehicle.get_license_plate()
        if plate in self.plate_to_ticket_mapping:
            return False
        return self.find_spot_for_vehicle(vehicle) is not None

    def count_available(self, size: VehicleSize | None = None) -> int:
        if size is not None:
            return sum(1 for spot in self.available_spots.get(size, []) if spot.is_available())
        return sum(
            1
            for spot_size in SIZE_ORDER
            for spot in self.available_spots.get(spot_size, [])
            if spot.is_available()
        )

    def is_full(self) -> bool:
        return self.count_available() == 0

    def park_vehicle(self, vehicle: Vehicle, passenger_name: str) -> Optional[Ticket]:
        if not self.can_park(vehicle):
            return None

        spot = self.find_spot_for_vehicle(vehicle)
        if spot is None:
            return None

        plate = vehicle.get_license_plate()
        spot.occupy(vehicle)
        self.plate_to_spot_mapping[plate] = spot
        ticket = Ticket(passenger_name, vehicle, spot, datetime.now())
        self.plate_to_ticket_mapping[plate] = ticket
        return ticket

    def unpark_vehicle(self, vehicle: Vehicle) -> Optional[Ticket]:
        plate = vehicle.get_license_plate()
        spot = self.plate_to_spot_mapping.get(plate)
        ticket = self.plate_to_ticket_mapping.get(plate)
        if spot is None or ticket is None:
            return None

        ticket.close(datetime.now())
        spot.vacate()
        del self.plate_to_spot_mapping[plate]
        del self.plate_to_ticket_mapping[plate]
        return ticket

    def get_available_spots(self) -> Dict[VehicleSize, List[ParkingSpot]]:
        return {
            size: list(spots) for size, spots in self.available_spots.items()
        }

    def get_plate_to_spot_mapping(self) -> Dict[str, ParkingSpot]:
        return dict(self.plate_to_spot_mapping)
