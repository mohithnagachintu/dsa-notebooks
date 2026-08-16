from datetime import datetime

from domain import Payment, Receipt, Ticket
from enums import PaymentMethod


class PaymentService:
    def process_payment(
        self,
        ticket: Ticket,
        fare: float,
        method: PaymentMethod,
    ) -> Receipt:
        payment = Payment(
            ticket_id=ticket.ticket_id,
            amount=fare,
            method=method,
            paid_at=datetime.now(),
        )
        return Receipt(ticket=ticket, payment=payment, fare=fare)
