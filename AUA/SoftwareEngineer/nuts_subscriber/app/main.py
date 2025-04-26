# app/main.py
import time
from app.models import Message
from app.service import save_message

print("Starting simulated Nuts subscription...")

while True:
    timestamp = int(time.time() * 1000)
    content = f"Test message at {timestamp}"
    msg = Message(content=content)
    print(f"Processing: {msg.content}")
    save_message(msg)
    time.sleep(1)
