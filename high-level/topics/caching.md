# Caching

> **Caching** is a process of storing frequently accessed data in a temporary storage location (cache) to enable faster access to that data in the future. Caching is commonly used to improve the performance and scalability of systems by reducing the need to repeatedly fetch data from slower storage systems (e.g., databases, external APIs).

- [Caching](#caching)
  - [Types of Caching](#types-of-caching)
    - [In-Memory Caching](#in-memory-caching)
    - [Distributed Caching](#distributed-caching)
    - [Client-Side Caching](#client-side-caching)
  - [Cache Strategies](#cache-strategies)
    - [Cache-Aside (Lazy Loading)](#cache-aside-lazy-loading)
    - [Write-Through](#write-through)
    - [Write-Back (Write-Behind)](#write-back-write-behind)

## Types of Caching

### In-Memory Caching

- **In-Memory Caching** involves storing data in the RAM of a server or application instance.
- This allows for extremely fast data retrieval, as accessing data from memory is significantly quicker than accessing it from disk-based storage systems.
- We have to consider in-memory caching is volatile, meaning that data stored in memory is lost when the application or server is restarted.

### Distributed Caching

- **Distributed Caching** involves storing cached data across multiple servers or nodes in a distributed system.
- This approach allows for greater scalability and fault tolerance, as cached data can be shared and accessed by multiple application instances.
- It can be complex to implement and manage, as it requires coordination between multiple nodes to ensure data consistency and availability.

  ![Distributed Caching Diagram](https://miro.medium.com/v2/resize:fit:720/format:webp/1*5NCPw2e-hhLnd0_FwJrE8A.png)

- **Example**
  - Suppose we have an e-commerce website that serves user across the globe. To improve performance we can use a distributed caching system like Redis or Memcached.
  - When a user requests products details, the application first checks the node closest to the user for the cached data. If the data is found in the cache, it is returned to the user quickly. If not, the application fetches the data from the database, stores it in the distributed cache, and then returns it to the user.

### Client-Side Caching

- **Client-Side Caching** involves storing cached data on the client side, such as in a web browser or mobile application.
- This type of caching are useful for reducing latency and improving performance for frequently accessed resources, such as images, scripts, and stylesheets.
- To implement client-side caching, we can use techniques such as HTTP caching headers (e.g., Cache-Control, ETag) to control how resources are cached by the client.
  - **`Cache-Control`:** Specifies caching directives for the client and intermediate caches, such as max-age, no-cache, and public/private. Until the max-age expires, the client can use the cached version without revalidating it with the server.
  - **`ETag`:** A unique identifier assigned to a specific version of a resource. When the client makes a subsequent request for the same resource, it can include the ETag in the `If-None-Match` header. If the resource has not changed, the server responds with a 304 Not Modified status, allowing the client to use its cached version.
- Local storage mechanisms, such as IndexedDB or localStorage, can also be used to store larger amounts of data on the client side for offline access and improved performance.

## Cache Strategies

- Cache strategies determine how data is stored, retrieved, and invalidated in a caching system. It's totally depends on the use case and requirements of the application. Some common cache strategies include:

### Cache-Aside (Lazy Loading)

- In the **Cache-Aside** strategy, the application first checks the cache for the requested data. If the data is found in the cache (cache hit), it is returned to the requester. If the data is not found in the cache (cache miss), the application fetch data from the database oer other data source, stores it in the cache, and then returns it to the requester.
- It's simple, flexible but requires careful management of the cache to ensure data consistency and freshness.

  ![Cache-Aside Strategy Diagram](https://miro.medium.com/v2/resize:fit:720/format:webp/1*uaevKUkspqvc-0FjqYHq3A.png)

### Write-Through

- In the **Write Through** strategy, data is written to both the cache and the underlying data store simultaneously. This ensures that the cache always contains the most up-to-date data, but it can introduce additional latency for write operations since both the cache and data store need to be updated.
- It's useful for applications that require strong data consistency between the cache and the data store.
- It's increase the write latency.

  ![Write-Through Strategy Diagram](https://miro.medium.com/v2/resize:fit:720/format:webp/1*_5bhlCaCnZnUbk88vSB91A.png)

### Write-Back (Write-Behind)

- In the **Write-Back** strategy, data is first written to the cache, and the write operation to the underlying data store is deferred until a later time. This can improve write performance, as the application can continue processing without waiting for the data store to be updated.
- However, it introduces the risk of data loss if the cache is not properly synchronized with the data store, and it requires careful management to ensure data consistency.
- It's useful for applications that require high write throughput and can tolerate eventual consistency between the cache and the data store.

  ![Write-Back Strategy Diagram](https://miro.medium.com/v2/resize:fit:720/format:webp/1*AI01VzBqhoWLrH8TNZgrFA.png)

- The write-back strategy can be implemented using techniques such as message queues or background workers to handle the deferred write operations to the data store.
