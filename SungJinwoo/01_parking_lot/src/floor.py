from dataclasses import dataclass, field
from typing import Dict, List

from domain import ParkingSpot
from enums import SIZE_ORDER, VehicleSize
from implementations.spots import create_spots_for_floor


@dataclass
class Floor:
    level: int
    spots: Dict[VehicleSize, List[ParkingSpot]] = field(default_factory=dict)

    @property
    def name(self) -> str:
        return f"Floor {self.level}"

    def count_available(self, size: VehicleSize | None = None) -> int:
        if size is not None:
            return sum(1 for spot in self.spots.get(size, []) if spot.is_available())
        return sum(
            1
            for spot_size in SIZE_ORDER
            for spot in self.spots.get(spot_size, [])
            if spot.is_available()
        )

    def is_full(self) -> bool:
        return self.count_available() == 0


def create_floor(
    level: int,
    compact: int = 0,
    medium: int = 0,
    large: int = 0,
) -> Floor:
    spots = create_spots_for_floor(level, compact, medium, large)
    return Floor(level=level, spots=spots)


def flatten_spots(floors: List[Floor]) -> Dict[VehicleSize, List[ParkingSpot]]:
    combined: Dict[VehicleSize, List[ParkingSpot]] = {}
    for floor in floors:
        for size, spots in floor.spots.items():
            combined.setdefault(size, []).extend(spots)
    return combined
