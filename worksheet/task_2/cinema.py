import sqlite3


def customer_tickets(conn, customer_id):
    cursor = conn.cursor()
    cursor.execute("""
        SELECT films.title, screenings.screen, tickets.price
        FROM tickets
        JOIN screenings ON tickets.screening_id = screenings.screening_id
        JOIN films ON screenings.film_id = films.film_id
        WHERE tickets.customer_id = ?
        ORDER BY films.title ASC;
    """, (customer_id,))
    return cursor.fetchall()


def screening_sales(conn):
    cursor = conn.cursor()
    cursor.execute("""
        SELECT screenings.screening_id, films.title, COUNT(tickets.ticket_id) AS tickets_sold
        FROM screenings
        JOIN films ON screenings.film_id = films.film_id
        LEFT JOIN tickets ON screenings.screening_id = tickets.screening_id
        GROUP BY screenings.screening_id, films.title
        ORDER BY tickets_sold DESC;
    """)
    return cursor.fetchall()


def top_customers_by_spend(conn, limit):
    cursor = conn.cursor()
    cursor.execute("""
        SELECT customers.customer_name, SUM(tickets.price) AS total_spent
        FROM customers
        JOIN tickets ON customers.customer_id = tickets.customer_id
        GROUP BY customers.customer_id, customers.customer_name
        ORDER BY total_spent DESC
        LIMIT ?;
    """, (limit,))
    return cursor.fetchall()