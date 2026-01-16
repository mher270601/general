# app/service.py
from app.db import get_connection
from app.models import Message
from datetime import datetime


def save_message(message: Message):
    try:
        conn = get_connection()
        cursor = conn.cursor()
        cursor.execute(
            "INSERT INTO messages (content, created_at) VALUES (%s, %s)",
            (message.content, message.created_at or datetime.now())
        )
        conn.commit()
        cursor.close()
        conn.close()
        print("Message saved.")
    except Exception as e:
        print(f"Failed to save message: {e}")
