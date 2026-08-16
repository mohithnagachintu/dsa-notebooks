from typing import Dict, List

from domain import ParkingSpot, Vehicle
from enums import SIZE_RANK, VehicleSize


class ParkingSpotImpl(ParkingSpot):
    def __init__(self, size: VehicleSize, spot_id: str) -> None:
        self._size = size
        self._spot_id = spot_id
        self._occupied = False
        self._vehicle: Vehicle | None = None

    def get_spot_id(self) -> str:
        return self._spot_id

    def is_available(self) -> bool:
        return not self._occupied

    def occupy(self, vehicle: Vehicle) -> None:
        if not self._can_fit(vehicle):
            raise ValueError(
                f"{vehicle.get_type().value} cannot fit in spot {self._spot_id}"
            )
        self._occupied = True
        self._vehicle = vehicle

    def vacate(self) -> None:
        self._occupied = False
        self._vehicle = None

    def get_size(self) -> VehicleSize:
        return self._size

    def _can_fit(self, vehicle: Vehicle) -> bool:
        return SIZE_RANK[self._size] >= SIZE_RANK[vehicle.get_size()]


def create_spots_for_floor(
    floor_level: int,
    compact: int = 0,
    medium: int = 0,
    large: int = 0,
) -> Dict[VehicleSize, List[ParkingSpot]]:
    prefix = f"F{floor_level}-"
    spots: Dict[VehicleSize, List[ParkingSpot]] = {}
    if compact:
        spots[VehicleSize.SMALL] = [
            ParkingSpotImpl(VehicleSize.SMALL, f"{prefix}S-{index}")
            for index in range(1, compact + 1)
        ]
    if medium:
        spots[VehicleSize.MEDIUM] = [
            ParkingSpotImpl(VehicleSize.MEDIUM, f"{prefix}M-{index}")
            for index in range(1, medium + 1)
        ]
    if large:
        spots[VehicleSize.LARGE] = [
            ParkingSpotImpl(VehicleSize.LARGE, f"{prefix}L-{index}")
            for index in range(1, large + 1)
        ]
    return spots


def create_spots(
    compact: int = 0,
    medium: int = 0,
    large: int = 0,
) -> Dict[VehicleSize, List[ParkingSpot]]:
    return create_spots_for_floor(1, compact, medium, large)
