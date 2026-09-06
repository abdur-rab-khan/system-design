# Types of Caching

## In-Memory Caching

- **In-Memory Caching** involves storing data in the RAM of a server or application instance.
- This allows for extremely fast data retrieval, as accessing data from memory is significantly quicker than accessing it from disk-based storage systems.
- We have to consider in-memory caching is volatile, meaning that data stored in memory is lost when the application or server is restarted.

## Distributed Caching

- **Distributed Caching** involves storing cached data across multiple servers or nodes in a distributed system.
- This approach allows for greater scalability and fault tolerance, as cached data can be shared and accessed by multiple application instances.
- It can be complex to implement and manage, as it requires coordination between multiple nodes to ensure data consistency and availability.

  ![Distributed Caching Diagram](https://miro.medium.com/v2/resize:fit:720/format:webp/1*5NCPw2e-hhLnd0_FwJrE8A.png)

- **Example**
  - Suppose we have an e-commerce website that serves user across the globe. To improve performance we can use a distributed caching system like Redis or Memcached.
  - When a user requests products details, the application first checks the node closest to the user for the cached data. If the data is found in the cache, it is returned to the user quickly. If not, the application fetches the data from the database, stores it in the distributed cache, and then returns it to the user.

## Client-Side Caching

- **Client-Side Caching** involves storing cached data on the client side, such as in a web browser or mobile application.
- This type of caching are useful for reducing latency and improving performance for frequently accessed resources, such as images, scripts, and stylesheets.
- To implement client-side caching, we can use techniques such as HTTP caching headers (e.g., Cache-Control, ETag) to control how resources are cached by the client.
  - **`Cache-Control`:** Specifies caching directives for the client and intermediate caches, such as max-age, no-cache, and public/private. Until the max-age expires, the client can use the cached version without revalidating it with the server.
  - **`ETag`:** A unique identifier assigned to a specific version of a resource. When the client makes a subsequent request for the same resource, it can include the ETag in the `If-None-Match` header. If the resource has not changed, the server responds with a 304 Not Modified status, allowing the client to use its cached version.
- Local storage mechanisms, such as IndexedDB or localStorage, can also be used to store larger amounts of data on the client side for offline access and improved performance.
