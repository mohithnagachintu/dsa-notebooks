from enums import VehicleSize, VehicleType
from domain import Vehicle


class Car(Vehicle):
    def __init__(self, license_plate: str) -> None:
        self.license_plate = license_plate

    def get_size(self) -> VehicleSize:
        return VehicleSize.MEDIUM

    def get_type(self) -> VehicleType:
        return VehicleType.CAR

    def get_license_plate(self) -> str:
        return self.license_plate


class Motorcycle(Vehicle):
    def __init__(self, license_plate: str) -> None:
        self.license_plate = license_plate

    def get_size(self) -> VehicleSize:
        return VehicleSize.SMALL

    def get_type(self) -> VehicleType:
        return VehicleType.MOTORCYCLE

    def get_license_plate(self) -> str:
        return self.license_plate


class Bus(Vehicle):
    def __init__(self, license_plate: str) -> None:
        self.license_plate = license_plate

    def get_size(self) -> VehicleSize:
        return VehicleSize.LARGE

    def get_type(self) -> VehicleType:
        return VehicleType.BUS

    def get_license_plate(self) -> str:
        return self.license_plate
