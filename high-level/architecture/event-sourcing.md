# Event Sourcing

> **Event Sourcing** is a design pattern, where state changes are logged as a sequence of events in a append-only store. We choose that event logs as the source of truth for our application state, rather than storing the current state directly. Using event sourcing, we update the current state by replaying the logged events.

## Key Concepts

1. **Event**: An event represents a significant change in the state of the application. Each event is immutable and contains all the necessary information to describe the change.
2. **Event Store**: An event store is a specialized database that stores events in an append-only manner. It allows for efficient retrieval and replay of events. such as EventStoreDB, Apache Kafka, or custom implementations using traditional databases.
3. **Aggregate**: An aggregate is a cluster of domain objects that can be treated as a single unit. In event sourcing, aggregates are responsible for generating events based on commands and applying those events to update their state.
4. **Command**: A command is a request to perform an action that may result in one or more events being generated. Commands are typically validated before being processed by the aggregate.
5. **Snapshot**: A snapshot is a point-in-time representation of an aggregate's state. Snapshots can be used to optimize the replay of events by allowing the system to start from a known state rather than replaying all events from the beginning.
6. **Event Replay**: Event replay is the process of reapplying events from the event store to reconstruct the current state of an aggregate. This is often done during system startup or when rebuilding state after a failure.
7. **Materialized View**: A materialized view is a read-optimized representation of the current state derived from the event store. It is often used to provide efficient querying capabilities for the application.

## Benefits

- **Auditability**: Since all state changes are logged as events, it is easy to trace the history of changes and understand how the current state was derived.
- **Scalability**: Event sourcing can improve scalability by allowing for efficient event storage and retrieval, as well as enabling distributed systems to process events independently.
- **Flexibility**: Event sourcing allows for easy modification of business logic by replaying events with updated logic, enabling features like retroactive changes and versioning.
- **Decoupling**: Event sourcing promotes a decoupled architecture, where different components can interact through events, reducing dependencies and improving maintainability.
- **Temporal Queries**: Event sourcing allows for querying the state of the system at any point in time by replaying events up to a specific moment.
- **Integration**: Event sourcing can facilitate integration with other systems by providing a clear and consistent event log that can be consumed by external services.
- **Resilience**: In the event of failures, the system can recover by replaying events from the event store, ensuring data integrity and consistency.
- **Event-Driven Architecture**: Event sourcing naturally aligns with event-driven architectures, enabling real-time processing and responsiveness to changes in the system.

## Challenges

- **Complexity**: Implementing event sourcing can introduce additional complexity to the system, requiring careful design and consideration of event schemas, versioning, and consistency.
- **Event Versioning**: As the application evolves, event schemas may change, requiring strategies for handling versioning and backward compatibility.
- **Storage Requirements**: Storing all events can lead to increased storage requirements, especially for long-lived applications with frequent state changes.
- **Eventual Consistency**: In distributed systems, event sourcing may lead to eventual consistency, where different components may have slightly different views of the state until all events are processed.

## Use Cases

- **Financial Systems**: Event sourcing is commonly used in financial applications to track transactions and account balances, providing a clear audit trail of all changes.
- **E-commerce Platforms**: E-commerce systems can benefit from event sourcing by tracking orders, inventory changes, and customer interactions.
- **Collaboration Tools**: Applications that require real-time collaboration, such as document editing or project management tools, can use event sourcing to manage changes and synchronize state across users.
- **Gaming**: Event sourcing can be used in gaming applications to track player actions, game state changes, and achievements, enabling features like replay and analytics.
- **IoT Systems**: Event sourcing can help manage the state of IoT devices by logging sensor data and device interactions, allowing for analysis and monitoring over time.

## Example

[![Video Processing Event Sourcing](./images/event-sourcing-video-processing.png)](https://app.eraser.io/workspace/ApXeA5bGhvGJZbPJYqcD?elements=7LxHIs3n7-Qxk4eVTv1cfA)

- In the above architecture, we have an event-sourced system for processing video uploads and encodes.

- When a user uploads a video, we temporarily store the video in a storage service like AWS S3 after uploading we call lambda function to emit a **`"VideoUploaded"`** event to Kafka.
- The **`"VideoUploaded"`** event is consumed by the Video Processing Service, which generates a **`"VideoProcessingStarted"`** event and begins processing the video (e.g., encoding it into different formats).
- Once the video processing is complete, the service emits a **`"VideoProcessingCompleted"`** event.
- After the **`VideoProcessingCompleted`** event is emitted, we update the Materialized View Database (e.g., DynamoDB) to reflect the current state of the video (e.g., available formats, processing status), then emit a "VideoAvailable" event.
