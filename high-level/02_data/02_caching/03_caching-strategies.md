# Cache Strategies

- Cache strategies determine how data is stored, retrieved, and invalidated in a caching system. It's totally depends on the use case and requirements of the application. Some common cache strategies include:

## Cache-Aside (Lazy Loading)

- In the **Cache-Aside** strategy, the application first checks the cache for the requested data. If the data is found in the cache (cache hit), it is returned to the requester. If the data is not found in the cache (cache miss), the application fetch data from the database oer other data source, stores it in the cache, and then returns it to the requester.
- It's simple, flexible but requires careful management of the cache to ensure data consistency and freshness.

  ![Cache-Aside Strategy Diagram](https://miro.medium.com/v2/resize:fit:720/format:webp/1*uaevKUkspqvc-0FjqYHq3A.png)

## Write-Through

- In the **Write Through** strategy, data is written to both the cache and the underlying data store simultaneously. This ensures that the cache always contains the most up-to-date data, but it can introduce additional latency for write operations since both the cache and data store need to be updated.
- It's useful for applications that require strong data consistency between the cache and the data store.
- It's increase the write latency.

  ![Write-Through Strategy Diagram](https://miro.medium.com/v2/resize:fit:720/format:webp/1*_5bhlCaCnZnUbk88vSB91A.png)

## Write-Back (Write-Behind)

- In the **Write-Back** strategy, data is first written to the cache, and the write operation to the underlying data store is deferred until a later time. This can improve write performance, as the application can continue processing without waiting for the data store to be updated.
- However, it introduces the risk of data loss if the cache is not properly synchronized with the data store, and it requires careful management to ensure data consistency.
- It's useful for applications that require high write throughput and can tolerate eventual consistency between the cache and the data store.

  ![Write-Back Strategy Diagram](https://miro.medium.com/v2/resize:fit:720/format:webp/1*AI01VzBqhoWLrH8TNZgrFA.png)

- The write-back strategy can be implemented using techniques such as message queues or background workers to handle the deferred write operations to the data store.
