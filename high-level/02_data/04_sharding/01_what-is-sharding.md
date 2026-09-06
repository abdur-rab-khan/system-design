# Sharding

> Sharding is a database architecture pattern in which data is split into smaller pieces (called shards) across the server and region. Each shard contains a subset of the data, allowing for horizontal scaling and improved performance.

## Why Sharding?

- **Scalability**: As the amount of data grows, a single database instance may become a bottleneck. Sharding allows you to distribute the load across multiple servers.
- **Performance**: By distributing data, queries can be executed in parallel across multiple shards, reducing latency and improving response times.
- **Availability**: If one shard goes down, the others can continue to operate, improving overall system availability.
- **Cost Efficiency**: Sharding can help optimize resource usage by allowing you to use smaller, less expensive servers instead of a single large one.
