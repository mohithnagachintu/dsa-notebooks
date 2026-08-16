from domain import FareStrategy, Ticket
from enums import VehicleSize


class BasicFareStrategy(FareStrategy):
    def __init__(
        self,
        small_vehicle_fare: float = 1.0,
        medium_vehicle_fare: float = 2.0,
        large_vehicle_fare: float = 3.0,
    ) -> None:
        self._rates = {
            VehicleSize.SMALL: small_vehicle_fare,
            VehicleSize.MEDIUM: medium_vehicle_fare,
            VehicleSize.LARGE: large_vehicle_fare,
        }

    def calculate_fare(self, ticket: Ticket) -> float:
        rate = self._rates[ticket.vehicle.get_size()]
        hours = ticket.get_duration().total_seconds() / 3600
        return rate * hours


class PeakHourFareStrategy(FareStrategy):
    def __init__(
        self,
        small_vehicle_fare: float = 1.0,
        medium_vehicle_fare: float = 2.0,
        large_vehicle_fare: float = 3.0,
    ) -> None:
        self._rates = {
            VehicleSize.SMALL: small_vehicle_fare,
            VehicleSize.MEDIUM: medium_vehicle_fare,
            VehicleSize.LARGE: large_vehicle_fare,
        }

    def calculate_fare(self, ticket: Ticket) -> float:
        rate = self._rates[ticket.vehicle.get_size()]
        hours = ticket.get_duration().total_seconds() / 3600
        return rate * hours * 1.5


class WeekendFareStrategy(FareStrategy):
    def __init__(
        self,
        small_vehicle_fare: float = 1.0,
        medium_vehicle_fare: float = 2.0,
        large_vehicle_fare: float = 3.0,
    ) -> None:
        self._rates = {
            VehicleSize.SMALL: small_vehicle_fare,
            VehicleSize.MEDIUM: medium_vehicle_fare,
            VehicleSize.LARGE: large_vehicle_fare,
        }

    def calculate_fare(self, ticket: Ticket) -> float:
        rate = self._rates[ticket.vehicle.get_size()]
        hours = ticket.get_duration().total_seconds() / 3600
        return rate * hours * 1.2
