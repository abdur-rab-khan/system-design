# Sharding

> Sharding is a database architecture pattern in which data is split into smaller pieces (called shards) and distributed across multiple database instances. Each shard contains a subset of the data, allowing for horizontal scaling and improved performance.

## Why Sharding?

- **Scalability**: As the amount of data grows, a single database instance may become a bottleneck. Sharding allows you to distribute the load across multiple servers.
- **Performance**: By distributing data, queries can be executed in parallel across multiple shards, reducing latency and improving response times.
- **Availability**: If one shard goes down, the others can continue to operate, improving overall system availability.
- **Cost Efficiency**: Sharding can help optimize resource usage by allowing you to use smaller, less expensive servers instead of a single large one.

## How Sharding Works

- **Shard Key**: A shard key is a specific field or set of fields used to determine how data is distributed across shards. Choosing an appropriate shard key is crucial for effective sharding, there are multiple strategies for selecting a shard key, such as range-based, hash-based, or directory-based sharding.
- **Data Distribution**: Once a shard key is chosen, the database uses it to determine which shard a particular piece of data belongs to. For example, in a hash-based sharding strategy, the database might apply a hash function to the shard key and use the result to assign the data to a specific shard.
- **Query Routing**: When a query is made, the database system uses the shard key to route the query to the appropriate shard(s). This ensures that only the relevant shards are queried, improving efficiency.

![Sharding Diagram](https://media.geeksforgeeks.org/wp-content/uploads/20231228162624/Sharding.jpg)

## Sharding Strategies

### 1. Key-Based Sharding

- Data is distributed based on a specific key, such as user ID or geographic location.
- Each shard contains data for a specific range or hash of the key.
- Example: Users with IDs 1-1000 are stored in Shard 1, 1001-2000 in Shard 2, etc.

![Key-Based Sharding](https://media.geeksforgeeks.org/wp-content/uploads/20231228162700/Key-Based-Sharding.jpg)

### 2. Range-Based Sharding

- Data is divided into ranges based on the shard key.
- Each shard contains data within a specific range of values.
- Example: Orders from January to March are stored in Shard 1, April to June in Shard 2, etc, or users with last names starting with A-M in Shard 1 and N-Z in Shard 2.

![Range-Based Sharding](https://media.geeksforgeeks.org/wp-content/uploads/20230831152413/range-based-sharding.png)

### 3. Vertical Sharding

- Different tables or columns are stored in different shards.
- Useful for separating frequently accessed data from less frequently accessed data.
- Example: User profile data in one shard and user activity logs in another.

![Vertical Sharding](https://media.geeksforgeeks.org/wp-content/uploads/20230831152524/vertical-sharding.png)
