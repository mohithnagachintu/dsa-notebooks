"""Parking Lot LLD demo."""

from enums import PaymentMethod, VehicleType
from floor import create_floor
from implementations import (
    BasicFareStrategy,
    PeakHourFareStrategy,
    VehicleFactory,
    WeekendFareStrategy,
)
from services import FareCalculator, ParkingLot, PaymentService


def main() -> None:
    floors = [
        create_floor(level=1, compact=2, medium=2, large=1),
        create_floor(level=2, compact=1, medium=1, large=0),
    ]

    parking_lot = ParkingLot(
        name="City Center Parking",
        floors=floors,
        fare_calculator=FareCalculator(
            basic=BasicFareStrategy(),
            peak=PeakHourFareStrategy(),
            weekend=WeekendFareStrategy(),
        ),
        payment_service=PaymentService(),
    )

    vehicles = [
        (VehicleFactory.create(VehicleType.MOTORCYCLE, "M-101"), "Rider A"),
        (VehicleFactory.create(VehicleType.CAR, "C-202"), "Driver B"),
        (VehicleFactory.create(VehicleType.BUS, "B-303"), "Operator C"),
    ]

    print(f"=== {parking_lot.name} ===")
    print(f"Available spots: {parking_lot.count_available()}")
    print(f"Lot full: {parking_lot.is_full()}")

    print("\n=== Entry ===")
    for vehicle, passenger in vehicles:
        if not parking_lot.can_park(vehicle):
            print(f"Cannot park {vehicle.get_license_plate()} — no spot")
            continue
        ticket = parking_lot.enter(vehicle, passenger)
        if ticket:
            print(
                f"Parked {vehicle.get_type().value} [{vehicle.get_license_plate()}] "
                f"-> ticket #{ticket.ticket_id}, spot {ticket.parking_spot.get_spot_id()} "
                f"({ticket.status.value})"
            )

    print("\n=== Double-park guard ===")
    duplicate = parking_lot.enter(
        VehicleFactory.create(VehicleType.CAR, "C-202"), "Duplicate"
    )
    print(f"Re-park C-202: {'blocked' if duplicate is None else 'allowed (bug)'}")

    print("\n=== Exit (unpark + fare + payment) ===")
    for vehicle, _ in vehicles:
        receipt = parking_lot.exit(vehicle, PaymentMethod.CARD)
        if receipt:
            print(
                f"Exit [{vehicle.get_license_plate()}] ticket #{receipt.ticket.ticket_id} "
                f"| spot {receipt.ticket.parking_spot.get_spot_id()} "
                f"| duration {receipt.ticket.get_duration()} "
                f"| fare ${receipt.fare:.2f} "
                f"| paid via {receipt.payment.method.value} "
                f"| status {receipt.ticket.status.value}"
            )

    print(f"\nAvailable spots after exit: {parking_lot.count_available()}")


if __name__ == "__main__":
    main()
