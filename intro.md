# System Design

> A system design is a process of breaking down a complex application or service into smaller, manageable components. It involves defining the architecture, components, modules, interfaces, and data for a system to satisfy specified requirements. \
> System design is crucial for building scalable, reliable, and maintainable systems, as it helps in understanding how different parts of the system interact with each other and how they can be optimized for performance and efficiency.

- [System Design](#system-design)
  - [Key Concepts](#key-concepts)
    - [Performance and Scalability](#performance-and-scalability)
    - [Latency vs Throughput](#latency-vs-throughput)
    - [Availability vs Consistency vs Partition Tolerance (CAP Theorem)](#availability-vs-consistency-vs-partition-tolerance-cap-theorem)

## Key Concepts

### Performance and Scalability

| Performance                                                                                                     | Scalability                                                                                                                                     |
| --------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| **Performance** refers to how quickly a system can handle requests and deliver responses.                       | **Scalability** refers to a system's ability to handle increased load by adding resources.                                                      |
| It is often measured in terms of **_latency_** (response time) and **_throughput_** (requests per second).      | It can bue achieved through **_vertical scaling_** (adding more power to existing machines) or **_horizontal scaling_** (adding more machines). |
| Techniques to improve performance include **_caching_**, **_load balancing_**, and **_database optimization_**. | Techniques to improve scalability include **_sharding_**, **_replication_**, and using **_cloud services_**.                                    |
| Example: A web application that responds to user requests in under 200 milliseconds.                            | Example: A social media platform that can handle millions of users by adding more servers as needed. without dropping performance.              |

### Latency vs Throughput

| Latency                                                                                                                                                | Throughput                                                                                                                                                           |
| ------------------------------------------------------------------------------------------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Latency** refers to the time it takes for a system to respond to a request.                                                                          | **Throughput** refers to the number of requests a system can handle in a given time period.                                                                          |
| It is typically measured in milliseconds (ms).                                                                                                         | It is typically measured in requests per second (RPS) or transactions per second (TPS).                                                                              |
| Lower latency means faster response times.                                                                                                             | Higher throughput means the system can handle more load.                                                                                                             |
| Latency can be affected by various factors such as network delays (more time take to deliver data), inefficient algorithms and server processing time. | Throughput can be affected by the bandwidth limitations (more data that can be processed in a given time), limited resources (CPU, memory), and system architecture. |

- **Example:** To achieve **higher throughput**, We can use horizontal scaling (adding more servers) to distribute the load, but this may increase **latency** due to additional network hops.
  - To solve latency issues, we can implement caching mechanisms to store frequently accessed data closer to the user, reducing the time it takes to retrieve that data.
  - By balancing both latency and throughput, we can design a system that is both fast and capable of handling a large number of requests efficiently.

### Availability vs Consistency vs Partition Tolerance (CAP Theorem)
