# Types of Sharding

## 1. Key-Based Sharding

- Data is distributed based on a specific key, such as user ID or geographic location.
- Each shard contains data for a specific range or hash of the key.
- Example: Users with IDs 1-1000 are stored in Shard 1, 1001-2000 in Shard 2, etc.

![Key-Based Sharding](https://media.geeksforgeeks.org/wp-content/uploads/20231228162700/Key-Based-Sharding.jpg)

## 2. Range-Based Sharding

- Data is divided into ranges based on the shard key.
- Each shard contains data within a specific range of values.
- Example: Orders from January to March are stored in Shard 1, April to June in Shard 2, etc, or users with last names starting with A-M in Shard 1 and N-Z in Shard 2.

![Range-Based Sharding](https://media.geeksforgeeks.org/wp-content/uploads/20230831152413/range-based-sharding.png)

## 3. Vertical Sharding

- Different tables or columns are stored in different shards.
- Useful for separating frequently accessed data from less frequently accessed data.
- Example: User profile data in one shard and user activity logs in another.

![Vertical Sharding](https://media.geeksforgeeks.org/wp-content/uploads/20230831152524/vertical-sharding.png)
