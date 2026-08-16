from abc import ABC, abstractmethod
from dataclasses import dataclass, field
from datetime import datetime, timedelta
from typing import Optional

from enums import PaymentMethod, TicketStatus, VehicleSize, VehicleType


class Vehicle(ABC):

    @abstractmethod
    def get_size(self) -> VehicleSize:
        pass

    @abstractmethod
    def get_type(self) -> VehicleType:
        pass

    @abstractmethod
    def get_license_plate(self) -> str:
        pass


class ParkingSpot(ABC):

    @abstractmethod
    def get_spot_id(self) -> str:
        pass

    @abstractmethod
    def is_available(self) -> bool:
        pass

    @abstractmethod
    def occupy(self, vehicle: Vehicle) -> None:
        pass

    @abstractmethod
    def vacate(self) -> None:
        pass

    @abstractmethod
    def get_size(self) -> VehicleSize:
        pass


_ticket_counter = 0


@dataclass
class Ticket:
    passenger_name: str
    vehicle: Vehicle
    parking_spot: ParkingSpot
    entry_time: datetime
    exit_time: Optional[datetime] = None
    ticket_id: int = field(init=False)
    status: TicketStatus = field(init=False)

    def __post_init__(self) -> None:
        global _ticket_counter
        _ticket_counter += 1
        self.ticket_id = _ticket_counter
        self.status = TicketStatus.ACTIVE

    def close(self, exit_time: datetime) -> None:
        self.exit_time = exit_time
        self.status = TicketStatus.CLOSED

    def get_duration(self) -> timedelta:
        if self.exit_time is None:
            raise ValueError("Exit time is not set")
        return self.exit_time - self.entry_time


class FareStrategy(ABC):

    @abstractmethod
    def calculate_fare(self, ticket: Ticket) -> float:
        pass


@dataclass(frozen=True)
class Payment:
    ticket_id: int
    amount: float
    method: PaymentMethod
    paid_at: datetime


@dataclass(frozen=True)
class Receipt:
    ticket: Ticket
    payment: Payment
    fare: float
