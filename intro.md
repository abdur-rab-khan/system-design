# System Design

> A system design is a process of breaking down a complex application or service into smaller, manageable components. It involves defining the architecture, components, modules, interfaces, and data for a system to satisfy specified requirements. \
> System design is crucial for building scalable, reliable, and maintainable systems, as it helps in understanding how different parts of the system interact with each other and how they can be optimized for performance and efficiency.

- [System Design](#system-design)
  - [Key Concepts](#key-concepts)
    - [Performance and Scalability](#performance-and-scalability)
    - [Latency vs Throughput](#latency-vs-throughput)
    - [Availability vs Consistency vs Partition Tolerance (CAP Theorem)](#availability-vs-consistency-vs-partition-tolerance-cap-theorem)
      - [Consistency patterns](#consistency-patterns)
      - [Availability patterns](#availability-patterns)
    - [Horizontal Scaling vs Vertical Scaling](#horizontal-scaling-vs-vertical-scaling)
      - [Horizontal Scaling](#horizontal-scaling)
      - [Vertical Scaling](#vertical-scaling)
  - [System Design Topics](#system-design-topics)
    - [Load Balancing](#load-balancing)

## Key Concepts

### Performance and Scalability

| Performance                                                                                                     | Scalability                                                                                                                                    |
| --------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------- |
| **Performance** refers to how quickly a system can handle requests and deliver responses.                       | **Scalability** refers to a system's ability to handle increased load by adding resources.                                                     |
| It is often measured in terms of **_latency_** (response time) and **_throughput_** (requests per second).      | It can be achieved through **_vertical scaling_** (adding more power to existing machines) or **_horizontal scaling_** (adding more machines). |
| Techniques to improve performance include **_caching_**, **_load balancing_**, and **_database optimization_**. | Techniques to improve scalability include **_sharding_**, **_replication_**, and using **_cloud services_**.                                   |
| Example: A web application that responds to user requests in under 200 milliseconds.                            | Example: A social media platform that can handle millions of users by adding more servers as needed. without dropping performance.             |

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

- **Availability, Consistency, Partition Tolerance** are three critical properties of distributed systems, as defined by the CAP theorem.
  - **Consistency**: Every read receives the most recent write or an error. All nodes see the same data at the same time.
  - **Availability**: Every request receives a (non-error) response, without guarantee that it contains the most recent write. The system remains operational.
  - **Partition Tolerance**: The system continues to operate despite arbitrary message loss or failure of part of the system. The system can handle network partitions.

#### Consistency patterns

- Consistency patterns refer to the strategies and techniques used to ensure that data remains consistent across distributed systems. Some common consistency patterns include:

  - **Strong Consistency:**
    - Ensures that all nodes see the same data at the same time. This is often achieved through synchronous replication and consensus algorithms like Paxos or Raft.
    - Example: In a banking application, when a user transfers money from one account to another, strong consistency ensures that both accounts reflect the updated balance immediately.
  - **Eventual Consistency:**
    - Allows for temporary inconsistencies, with the guarantee that all nodes will eventually converge to the same state. This is often used in systems that prioritize availability and partition tolerance.
    - Example: In a social media application, when a user posts a new status update, it may take some time for all followers to see the update, but eventually, all followers will see the same content.
  - **Weak Consistency:**
    - Does not guarantee that all nodes will see the same data at the same time. This pattern is often used in systems where performance and availability are prioritized over consistency.
    - Example: In a caching system, a cached value may not reflect the most recent update from the database, but it provides faster access to frequently requested data.

- **Note:**
  - It's totally depends on the use case which consistency pattern to choose, sometime we may does not need strong consistency for all operations (e.g., read operations can be eventually consistent while write operations are strongly consistent), allowing for a balance between performance and data integrity.
  - Consistency only matters in distributed systems, in single node systems consistency is always guaranteed, because it does not depends on multiple nodes to agree on the data state.
  - Consistency can interrupt for various reasons like:
    - Network problems (node can't reach other nodes)
    - Node failures (node goes down)
    - Software bugs (bugs in the code that handles data replication or synchronization)

#### Availability patterns

- Availability patterns refer to the strategies and techniques used to ensure that a distributed system remains operational and responsive, even in the face of failures or high load. Some common availability patterns include:

  - **Fail-Over**
    - It involves two or more systems (primary and secondary) where the secondary system takes over if the primary system fails.
    - There are two types of fail-over:
      - **Active-passive:** The primary system handles all the traffic, and the secondary system remains on standby, ready to take over in case of failure.
      - **Active-active:** Both systems handle traffic simultaneously through load balancing, providing higher availability and fault tolerance.
    - Example: In a web application, if the primary server goes down, the secondary server automatically takes over to ensure continuous availability.
  - **Replication**
    - It involves creating multiple copies of data across different nodes or data centers to ensure that if one node fails, the data is still accessible from another node, common in databases.
    - There are two types of replication:
      - **Master-Master:** In this setup, multiple node can accept read and write operations, and data is synchronized between them, but it can lead to conflicts that need to be resolved.
      - **Master-Slave:** In this setup, one node (master) that handles all write operations, while other nodes (slaves) handle read operations, providing better read scalability. If the master fails, one of the slaves can be promoted to become the new master.
    - Example: In a distributed database, data is replicated across multiple nodes to ensure that if one node fails, the data can still be accessed from another node.

### Horizontal Scaling vs Vertical Scaling

- Scaling is the process of increasing a system's capacity to handle more load. There are two main types of scaling: **`horizontal scaling (increasing the number of machines)`** and **`vertical scaling (increasing the power of existing machines)`**.
- Both are comes with pros and cons, and the choice between them depends on the specific requirements and constraints of the system being designed.
- Horizontal scaling is often preferred for distributed systems, as it allows for better fault tolerance and can handle larger loads by distributing the workload across multiple machines.
- Vertical scaling can be simpler to implement, as it does not require changes to the system architecture, but it is limited by the maximum capacity of a single machine and can lead to a single point of failure.

#### Horizontal Scaling

- **Horizontal scaling**, also known as scaling out, involves adding more machines or nodes to a system to distribute the load and increase capacity.
- It is commonly used in distributed systems and cloud computing environments.
- It is often achieved through techniques such as **load balancing**, **sharding**, and **replication**.
- Horizontal scaling is more flexible but it can be hard to manage and maintain a large number of machines.
- It is commonly used in microservices architectures, web applications, and big data processing systems.

#### Vertical Scaling

- **Vertical scaling**, also known as scaling up, involves increasing the resources (CPU, RAM, storage) of an existing machine to handle more load.
- It is commonly used in traditional monolithic applications and databases.
- It is often achieved by upgrading hardware components or moving to more powerful servers.
- Vertical scaling is simpler to implement but it has limitations, as there is a maximum capacity for a single machine.
- It can lead to a single point of failure, as the entire system relies on a single machine.

## System Design Topics

### [Load Balancing](topics/load-balancing.md)
