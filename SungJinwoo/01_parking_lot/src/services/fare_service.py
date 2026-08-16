from domain import FareStrategy, Ticket


class FareCalculator:
    def __init__(
        self,
        basic: FareStrategy,
        peak: FareStrategy,
        weekend: FareStrategy,
    ) -> None:
        self.basic = basic
        self.peak = peak
        self.weekend = weekend

    def calculate_fare(self, ticket: Ticket) -> float:
        entry_time = ticket.entry_time
        if entry_time.weekday() in (5, 6):
            return self.weekend.calculate_fare(ticket)
        if 16 <= entry_time.hour <= 23:
            return self.peak.calculate_fare(ticket)
        return self.basic.calculate_fare(ticket)
