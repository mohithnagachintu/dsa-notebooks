from enum import Enum


class VehicleSize(Enum):
    SMALL = "small"
    MEDIUM = "medium"
    LARGE = "large"


class VehicleType(Enum):
    CAR = "car"
    MOTORCYCLE = "motorcycle"
    BUS = "bus"


class TicketStatus(Enum):
    ACTIVE = "active"
    CLOSED = "closed"


class PaymentMethod(Enum):
    CASH = "cash"
    CARD = "card"
    UPI = "upi"


SIZE_ORDER = (VehicleSize.SMALL, VehicleSize.MEDIUM, VehicleSize.LARGE)
SIZE_RANK = {size: rank for rank, size in enumerate(SIZE_ORDER, start=1)}
