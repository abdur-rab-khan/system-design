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
    - [Monolithic vs Microservices Architecture](#monolithic-vs-microservices-architecture)
      - [Monolithic Architecture](#monolithic-architecture)
      - [Microservices Architecture](#microservices-architecture)
    - [Single Point of Failure (SPOF)](#single-point-of-failure-spof)
  - [System Design Topics](#system-design-topics)
    - [Load Balancer](#load-balancer)
    - [Message Queues](#message-queues)
    - [Task Queues](#task-queues)
    - [Caching](#caching)
    - [Content Delivery Network (CDN)](#content-delivery-network-cdn)
    - [Event Driven Architecture (EDA)](#event-driven-architecture-eda)
      - [Advantages of EDA](#advantages-of-eda)
      - [Disadvantages of EDA](#disadvantages-of-eda)
      - [Publications and Subscribers](#publications-and-subscribers)
    - [DNS (Domain Name System)](#dns-domain-name-system)
    - [API Gateway](#api-gateway)

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

### Monolithic vs Microservices Architecture

#### Monolithic Architecture

- A **Monolithic Architecture** is a traditional software architecture where all components of an application are tightly coupled and run as a single unit, It commonly use single codebase for the entire application.
- In a monolithic architecture, all functionalities (e.g., user interface, business logic, data access) are integrated into a single application, making it easier to develop and deploy initially.
- However, If spike demands of one component, the entire application needs to be scaled, which can be inefficient and costly.
- In monolithic architecture, a failure in one component can affect the entire application, which can lead single point of failure.

- **Advantages and Disadvantages**

| Advantages                                     | Disadvantages                                                     |
| ---------------------------------------------- | ----------------------------------------------------------------- |
| Easier to develop and deploy initially.        | Difficult to scale individual components.                         |
| Simpler to test and debug.                     | Can become complex and hard to maintain as the application grows. |
| Better performance due to fewer network calls. | Limited flexibility in technology stack and deployment options.   |

#### Microservices Architecture

- A **Microservices Architecture** is a modern software architecture where an application is composed of small, independent services that communicate with each other through APIs.
- Each service is responsible for a specific functionality (e.g., user management, order processing, payment handling) and can be **developed**, **deployed**, and **scaled independently**.
- Spike demands of on service can be scaled independently without affecting other services, making it more efficient and cost-effective.
- In microservices architecture, a failure in one service does not necessarily affect the entire application, improving fault tolerance.
- In microservices architecture, reverse proxy servers (e.g., API Gateway) are often used to route requests to the appropriate services and handle cross-cutting concerns like authentication, logging, and rate limiting.
- Microservices architecture is commonly used in **cloud-native applications**, **e-commerce platforms**, and **large-scale web applications**.

  ![Monolithic vs Microservices Architecture](https://martinfowler.com/articles/microservices/images/decentralised-data.png)

- **Advantages and Disadvantages**

  | Advantages                                     | Disadvantages                                                        |
  | ---------------------------------------------- | -------------------------------------------------------------------- |
  | Allows independent development and deployment. | More complex to develop and deploy initially.                        |
  | Easier to scale individual services.           | Requires robust inter-service communication and management.          |
  | Improves fault tolerance and resilience.       | Can lead to increased latency due to network calls between services. |

### Single Point of Failure (SPOF)

- A **Single Point of Failure (SPOF)** is one of the most critical concepts in system design, which refers to a component or part of a system that, if it fails, will cause the entire system to fail or become unavailable.
- It is very important to think during build a system to eliminate or minimize single points of failure to ensure high availability and reliability.

- In system design every components can be a single point of failure, including:

  - **Servers:** If a single server hosts a critical application or service, its failure can lead to system downtime.
  - **Databases:** A single database instance can be a SPOF if it is not replicated or backed up.
  - **Network Components:** Routers, switches, or firewalls that are not redundant can become SPOFs.
  - **Load Balancer:** If there is only one load balancer and it fails, the entire system can become inaccessible.
  - **Entire Data Center:** If all resources are hosted in a single data center, a failure at that location can lead to complete system outage.

- **Strategies to Mitigate SPOF:**
  - **Redundancy:** Implementing redundant components (e.g., multiple servers, databases) to ensure that if one fails, another can take over, like we can use concepts like fail-over and replication.
  - **Load Balancing:** Distributing traffic across multiple servers to prevent any single server from becoming a SPOF.
  - **Geographic Distribution:** Hosting resources in multiple data centers or cloud regions to mitigate the risk of a single location failure.
  - **Regular Backups:** Ensuring that critical data is regularly backed up and can be restored in case of failure.
  - **Monitoring and Alerts:** Implementing monitoring systems to detect failures early and alert the relevant teams for quick response.
  - **Automated Failover:** Setting up automated failover mechanisms to switch to backup systems seamlessly in case of a failure.
  - **Decentralization:** Designing systems in a way that does not rely on a single component or service for critical functionality.

## System Design Topics

### [Load Balancer](topics/load-balancer.md)

- **Load balancers** are critical components in distributed systems, which help to distribute incoming network traffic across multiple servers or resources it totally depends on the load balancing algorithm used.
- By distributing the load, load balancers help to improve system performance, increase availability, and ensure fault tolerance.

### [Message Queues](topics/message-queue.md)

- **Message Queues** is similar to post office model, where messages are posted and eventually it will be delivered to the recipient.
- This is the same analogy we can use in software systems, where different components of a system communicate with each other by sending and receiving messages through a message queue.
- Message queues are commonly used in distributed systems to decouple components and enable asynchronous processing, particularly for tasks that are time-consuming (e.g., sending emails, processing images) or require reliable delivery (e.g., order processing, payment processing).

### Task Queues

- **Task Queue** is a type of message queue that is specifically designed for task which are compute-intensive and time-consuming in nature.
- Task queues are commonly used in distributed systems to offload tasks from the main application thread and process them asynchronously in the background, improving system performance and responsiveness.
- Task queues are often used for tasks which require significant processing time, such as image processing, data analysis, and sending emails.
- Popular task queue systems include **Celery** (Python), **RQ (Redis Queue)**, and **Bull** (Node.js).

### [Caching](topics/caching.md)

- **Caching** is a technique used to store frequently accessed data in a temporary storage location (cache) to improve system performance and reduce latency.
- This reduces the need to repeatedly fetch data from slower storage systems (e.g., databases, external APIs), resulting in faster response times and reduced load on backend systems.

### [Content Delivery Network (CDN)](topics/cdn.md)

- A **Content Delivery Network(CDN)** is the network of distributed servers across various geographical locations that servers cached static content (e.g., images, videos, stylesheets, scripts) to users based on their geographic location.
- CDNs help to improve website performance, reduce latency, and enhance user experience by delivering content from servers that are closer to the user's location using DNS routing and caching mechanisms.
- Popular CDN providers include **Cloudflare**, **Akamai**, **Amazon CloudFront**, and **Fastly**.

### Event Driven Architecture (EDA)

- An **Event driven architecture (EDA)** is a system design pattern used to build complex application, Using **EDA** we can easily scale, decouple system.
- Event driven architecture (EDA) consists four things:
  1. **Publisher:** A **Publisher** is a user which do something, like user place an order. In this case user (Publisher) make can event **place an order.**
  2. **Message:** A **Message** is the data, In place order case would be **`product_id`**, **`...other_product_details`**.
  3. **Message Broker:** A **Message Broker** is a peace of software that have task to distribute **Message** among all required **systems**.
  4. **Subscriber:** A **Subscriber** is **systems** that receive message, based on that it can perform tasks.

#### Advantages of EDA

1. **Loose coupling:** Subscribers does not depend on publisher, they only know about message broker. So if Subscribers needs to scale or change, publisher does not need to know about it.
2. **Scales Well:** As we know that in EDA publisher and subscriber are decoupled, so we can easily scale them independently based on the load.
3. **Good for real-time:** EDA is good for real-time applications where events need to be processed as they occur, like chat applications, online gaming, etc.
4. **Replay:** In EDA messages can be stored in message broker, so if subscriber goes down, it can process messages later when it comes back up.
5. **Asynchronous Processing:** EDA allows for asynchronous processing of events, which can improve system performance and responsiveness by decoupling event producers from event consumers.

#### Disadvantages of EDA

1. **Complexity:** EDA can introduce additional complexity to the system, as it requires managing message brokers, handling message delivery, and ensuring data consistency across different components.
2. **Debugging and Testing:** Debugging and testing event-driven systems can be more challenging, as events may be processed asynchronously and out of order, making it difficult to trace the flow of data and identify issues.
3. **Duplicate Messages:** In some cases, message brokers may deliver duplicate messages to subscribers, which can lead to data inconsistencies if not handled properly.

#### Publications and Subscribers

- In an event-driven architecture (EDA), **Publishers** and **Subscribers** are two key components that facilitate communication between different parts of the system.
- **Publishers:**
  - Publishers are the components or services that produce events based on certain actions or changes in the system.
  - For example, in an e-commerce application, a publisher could be the order service that generates an event when a new order is placed.
  - Publishers typically do not have knowledge of the subscribers; they simply send events to the message broker.
- **Subscribers:**
  - Subscribers are the components or services that consume events produced by publishers.
  - Continuing with the e-commerce example, a subscriber could be the inventory service that listens for order events and updates stock levels accordingly.
  - Subscribers register their interest in specific types of events with the message broker, which then delivers relevant events to them.
- **Example:**
  - In youtube when a user uploads a video (Publisher), an event is generated and sent to the message broker.
  - Various subscribers, such as the **video processing**, **notification service**, and **analytics service**, listen for the video upload event and perform their respective tasks (e.g., processing the video, sending notifications to subscribers, updating analytics data).

### [DNS (Domain Name System)](topics/dns.md)

- A **Domain Name System (DNS)** is a phonebook of the internet, which translates human-readable domain names (e.g., www.example.com) into machine-readable IP address (e.g., 18.10.0.100) that computers use to identify each other on the network.

### API Gateway

- A **API Gateway** is a server that acts as a gate keeper for API requests from clients to backend services.
- So using an API Gateway, clients can only interact with the API Gateway instead of directly communicating with backend services.
- It handles various responsibilities such as:
  - **Request Routing**: Directing incoming API requests to the appropriate backend services based on the request path, method, or other criteria.
  - **Authentication and Authorization**: Validating client credentials and ensuring that only authorized clients can access specific APIs.
  - **Rate Limiting and Throttling**: Controlling the number of requests a client can make to prevent abuse and ensure fair usage of resources.
  - **Load Balancing**: Distributing incoming API requests across multiple instances of backend services to ensure high availability and optimal resource utilization.
  - **Caching**: Storing frequently accessed API responses to reduce latency and improve performance.
  - **Transformation**: Modifying request and response data formats to ensure compatibility between clients and backend services.
