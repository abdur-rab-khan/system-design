# Load Balancer

> A **load balancer** is a device or software that distributes network or application traffic across a number of servers. The main goal of a load balancer is to optimize resource use, maximize throughput, minimize response time, and avoid overload on any single server.

- [Load Balancer](#load-balancer)
  - [Key Functions of Load Balancers](#key-functions-of-load-balancers)
  - [Distribution Algorithms](#distribution-algorithms)
  - [Disadvantages of Load Balancers](#disadvantages-of-load-balancers)
  - [Load Balancer vs Reverse Proxy](#load-balancer-vs-reverse-proxy)
  - [Implementation Examples](#implementation-examples)
    - [NGINX Load Balancer Example](#nginx-load-balancer-example)

## Key Functions of Load Balancers

1. **Traffic Distribution**: Load balancers distribute incoming traffic across multiple servers based on various algorithms (e.g., round-robin, least connections, IP hash).
2. **Health Monitoring**: They continuously monitor the health of servers to ensure traffic is only sent to healthy servers.
3. **Scalability**: Load balancers enable horizontal scaling by allowing additional servers to be added or removed from the pool without affecting the overall system.
4. **Fault Tolerance**: In case of server failure, load balancers can redirect traffic to other healthy servers, ensuring high availability.
5. **SSL Termination**: Load balancers can handle SSL encryption and decryption, So that backend servers can focus on processing requests.
6. **Session Persistence**: They can maintain session persistence (also known as sticky sessions) to ensure that a user's requests are consistently directed to the same server.

## Distribution Algorithms

- **Round Robin**: Distributes requests sequentially across the server pool.
- **Least Connections**: Directs traffic to the server with the fewest active connections.
- **IP Hash**: Uses the client's IP address to determine which server will handle the request.
- **Weighted Round Robin**: Assigns a weight to each server based on its capacity, distributing more requests to higher-capacity servers.

## Disadvantages of Load Balancers

- **Single Point of failure:** Sometimes load balancers can become a performance bottleneck or a single point of failure if not properly configured with redundancy.
- **Complexity:** Introducing load balancers adds complexity to the system architecture, which may require additional management and monitoring.

## Load Balancer vs Reverse Proxy

- A **load balancer** primarily focuses on distributing incoming traffic across multiple servers based on various factors such as **server load**, **health**, and **algorithms** to optimize resource utilization and ensure high availability.
  - **Use Case:** Suppose you have a web application hosted on multiple servers, We want to ensure that incoming user requests are evenly distribute across these servers to prevent any single server from becoming overwhelmed. A load balancer can be placed in front of these servers to distribute the incoming traffic based on the current load on each server.
- A **reverse proxy** is a server that sits between client devices and backend servers, forwarding client requests to the appropriate backend server. While reverse proxies is perform basic **security functions**, **caching**, and **SSL termination**, their main purpose is to act as an intermediary for requests from clients seeking resources from servers.
  - **Use Case:** Consider a scenario where you have **/api** (goes to NODE.JS), **/images** (goes to Static folder), and **/blog** (goes to WordPress) routes in your web application. A reverse proxy can be configured to route incoming requests to the appropriate backend server based on the URL path.
- In many cases, a load balancer can also function as a reverse proxy, but not all reverse proxies have load balancing capabilities.

## Implementation Examples

- **Hardware Load Balancers**: Dedicated physical devices designed to handle high volumes of traffic, such as F5 BIG-IP and Citrix ADC.
- **Software Load Balancers**: Applications that run on standard servers, such as NGINX, HAProxy, and Apache HTTP Server.
- **Cloud-based Load Balancers**: Managed load balancing services provided by cloud providers, such as AWS Elastic Load Balancing (ELB), Google Cloud Load Balancing, and Azure Load Balancer.

### NGINX Load Balancer Example

```nginx
http {
    upstream backend {
        server backend1.example.com;
        server backend2.example.com;
        server backend3.example.com;
    }

    server {
        listen 80;

        location / {
            proxy_pass http://backend;
        }
    }
}
```

- In this example, NGINX is configured as a load balancer that distributes incoming HTTP requests to three backend servers (backend1, backend2, and backend3) using the default round-robin algorithm.
