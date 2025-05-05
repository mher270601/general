A Python-based message processing service that simulates receiving messages and saves them into a PostgreSQL database using Docker.

## Technologies Used

- Python 3.10+
- psycopg2
- python-dotenv
- PostgreSQL (via Docker)
- Docker Compose

## Project Structure

- `app/main.py` – Simulates receiving and saving messages
- `app/db.py` – Manages DB connection using env variables
- `app/service.py` – Handles database insertions
- `app/models.py` – Message data structure
- `init.sql` – SQL script to create the `messages` table
- `.env` – Environment config (excluded from GitHub)
- `docker-compose.yml` – PostgreSQL service setup
- `requirements.txt` – Python dependencies
- `README.md` – Project overview and instructions

## Setup Instructions

### 1. Clone the repository

```bash
git clone https://github.com/<your-username>/nuts_subscriber.git
cd nuts_subscriber
```

### 2. Set up Python environment

```bash
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

### 3. Create `.env` file in project root

```
DB_NAME=nutsdb
DB_USER=postgres
DB_PASS=aaa000
DB_HOST=localhost
DB_PORT=5432
```

### 4. Start PostgreSQL with Docker

```bash
docker-compose up -d
```

Wait a few seconds to initialize.

### 5. Create the table

```bash
docker cp init.sql nuts_subscriber-postgres_nuts-1:/init.sql
docker exec -it nuts_subscriber-postgres_nuts-1 psql -U postgres -d nutsdb -f /init.sql
```

### 6. Run the application

```bash
PYTHONPATH=. python app/main.py
```

The app will simulate messages and save them every second.

### 7. Check messages in database

```bash
docker exec -it nuts_subscriber-postgres_nuts-1 psql -U postgres -d nutsdb -c "SELECT * FROM messages;"
```

## Notes

- Make sure Docker is running before starting the app.
- Do **not** include `.env` in version control.
- If `nutsdb` does not exist, add `POSTGRES_DB: nutsdb` to `docker-compose.yml`.



