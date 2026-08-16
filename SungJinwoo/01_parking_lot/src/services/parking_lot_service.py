from typing import List, Optional

from domain import Receipt, Ticket, Vehicle
from enums import PaymentMethod, VehicleSize
from floor import Floor, flatten_spots
from services.fare_service import FareCalculator
from services.parking_service import ParkingManager
from services.payment_service import PaymentService


class ParkingLot:
    def __init__(
        self,
        name: str,
        floors: List[Floor],
        fare_calculator: FareCalculator,
        payment_service: PaymentService,
    ) -> None:
        self.name = name
        self.floors = floors
        self._fare_calculator = fare_calculator
        self._payment_service = payment_service
        self._manager = ParkingManager(flatten_spots(floors))

    def enter(self, vehicle: Vehicle, passenger_name: str) -> Optional[Ticket]:
        return self._manager.park_vehicle(vehicle, passenger_name)

    def exit(self, vehicle: Vehicle, payment_method: PaymentMethod) -> Optional[Receipt]:
        ticket = self._manager.unpark_vehicle(vehicle)
        if ticket is None:
            return None
        fare = self._fare_calculator.calculate_fare(ticket)
        return self._payment_service.process_payment(ticket, fare, payment_method)

    def can_park(self, vehicle: Vehicle) -> bool:
        return self._manager.can_park(vehicle)

    def is_full(self) -> bool:
        return self._manager.is_full()

    def count_available(self, size: VehicleSize | None = None) -> int:
        return self._manager.count_available(size)

    def get_floors(self) -> List[Floor]:
        return list(self.floors)
