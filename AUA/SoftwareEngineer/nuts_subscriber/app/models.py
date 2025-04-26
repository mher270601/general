# app/models.py
from dataclasses import dataclass
from datetime import datetime

@dataclass
class Message:
    content: str
    created_at: datetime = None
