# SQL and NOSQL Databases

> While build real world applications, we often need to store and manage data. Two primary types of databases are SQL (Structured Query Language) databases and NoSQL (Not Only SQL) databases. Each has its own strengths and use cases.

## SQL Databases

SQL databases are relational databases that use **structured query language** for defining and manipulating data. They are based on a **table-based** structure, where data is organized into rows and columns.

### Key Features of SQL Databases:

- **Schema-based**: SQL databases require a predefined schema that defines the structure of the data.
- **ACID Compliance**: SQL databases adhere to ACID (Atomicity, Consistency, Isolation, Durability) properties, ensuring reliable transactions.
  - Atomicity: Transactions are all-or-nothing.
  - Consistency: Transactions bring the database from one valid state to another.
  - Isolation: Concurrent transactions do not interfere with each other.
  - Durability: Once a transaction is committed, it remains so, even in the event of a system failure.
- **Fixed Structure**: Data must conform to the defined schema, making it less flexible for unstructured data.
- **Query Language**: SQL databases use SQL (Structured Query Language) for querying and managing data.

## NoSQL Databases

NoSQL databases are non-relational databases that provide a flexible schema for storing and managing data. They are designed to handle large volumes of unstructured or semi-structured data.

### Key Features of NoSQL Databases:

- **Schema-less**: NoSQL databases do not require a predefined schema, allowing for more flexibility in data storage.
- **Scalability**: NoSQL databases are designed to scale out horizontally, making them suitable for handling large amounts of data and high traffic loads.
- **Variety of Data Models**: NoSQL databases support various data models, including document-based, key-value pairs, column-family, and graph databases.
- **Eventual Consistency**: Many NoSQL databases prioritize availability and partition tolerance over immediate consistency, leading to eventual consistency in distributed systems.
- **Query Methods**: NoSQL databases use various query methods depending on the data model, such as JSON queries for document databases or graph traversal for graph databases.
- **Base Principles**: NoSQL databases often follow the BASE (Basically Available, Soft state, Eventual consistency) principles.
  - Basically Available: The system guarantees availability.
  - Soft state: The state of the system may change over time, even without input.
  - Eventual consistency: The system will become consistent over time.

## When to Use SQL vs NoSQL

- **Use SQL Databases When**:

  - You need complex queries and transactions.
  - Data integrity and consistency are critical.
  - The data structure is well-defined and unlikely to change frequently.
  - You require ACID compliance for your applications.
  - It's best when strong relationship between data entities is needed, we can split data into multiple tables and use JOIN operations to retrieve related data.
  - It supports complex querying capabilities using SQL, making it easier to perform intricate data retrieval and manipulation tasks.

- **Use NoSQL Databases When**:
- You need to handle large volumes of unstructured or semi-structured data.
  - Scalability and flexibility are more important than strict consistency.
  - The data model is likely to evolve over time.
  - You require high availability and partition tolerance in distributed systems.
  - It considers faster read and write operations, making it suitable for applications with high throughput requirements, such as real-time analytics and big data processing.
