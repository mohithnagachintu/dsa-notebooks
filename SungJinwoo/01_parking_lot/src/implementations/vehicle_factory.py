from enums import VehicleType
from implementations.vehicles import Bus, Car, Motorcycle
from domain import Vehicle


class VehicleFactory:
    @staticmethod
    def create(vehicle_type: VehicleType, license_plate: str) -> Vehicle:
        if vehicle_type == VehicleType.CAR:
            return Car(license_plate)
        if vehicle_type == VehicleType.MOTORCYCLE:
            return Motorcycle(license_plate)
        if vehicle_type == VehicleType.BUS:
            return Bus(license_plate)
        raise ValueError(f"Unsupported vehicle type: {vehicle_type}")
