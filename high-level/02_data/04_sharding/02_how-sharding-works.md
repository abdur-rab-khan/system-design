# How Sharding Works

- **Shard Key**: A shard key is a specific field or set of fields used to determine how data is distributed across shards. Choosing an appropriate shard key is crucial for effective sharding, there are multiple strategies for selecting a shard key, such as range-based, hash-based, or directory-based sharding.
- **Data Distribution**: Once a shard key is chosen, the database uses it to determine which shard a particular piece of data belongs to. For example, in a hash-based sharding strategy, the database might apply a hash function to the shard key and use the result to assign the data to a specific shard.
- **Query Routing**: When a query is made, the database system uses the shard key to route the query to the appropriate shard(s). This ensures that only the relevant shards are queried, improving efficiency.

![Sharding Diagram](https://media.geeksforgeeks.org/wp-content/uploads/20231228162624/Sharding.jpg)
