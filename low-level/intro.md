# Low Level System Design

> **Low level system design** is the process of designing the internal components and architecture of a software system by using pre-define principles and patterns. It focuses on the detailed implementation of individual modules, classes, and functions, ensuring that they work together efficiently to meet the overall system requirements.

- [Low Level System Design](#low-level-system-design)
  - [Key Concepts](#key-concepts)
  - [OOPS Concepts](#oops-concepts)
  - [Design Principles](#design-principles)
  - [Design Patterns](#design-patterns)

## Key Concepts

1. **Modularity**: Breaking down the system into smaller, manageable components or modules that can be developed, tested, and maintained independently, Interface is a key aspect of modularity that defines the methods and properties that a module or class exposes to other parts of the system.
2. **Encapsulation**: Hiding the internal details of a module or class and exposing only the necessary interfaces for interaction.
3. **Cohesion**: Ensuring that the elements within a module or class are closely related and work together to achieve a specific functionality.
4. **Coupling**: Minimizing dependencies between different modules or classes to reduce the impact of changes and improve maintainability.
5. **Design Patterns**: Reusable solutions to common design problems, such as Singleton, Factory, Observer, and Strategy patterns.
6. **Data Structures**: Choosing appropriate data structures (e.g., arrays, linked lists, trees, hash tables) to optimize performance and memory usage.
7. **Algorithms**: Implementing efficient algorithms for data processing, searching, sorting, and other operations to enhance system performance.
8. **Error Handling**: Designing robust error handling mechanisms to manage exceptions and ensure system stability.
9. **Testing**: Creating unit tests, integration tests, and system tests to validate the functionality and performance of individual components and the overall system.
10. **Documentation**: Maintaining clear and comprehensive documentation of the design decisions, architecture, and implementation details for future reference and collaboration.

## OOPS Concepts

- `OOPS (Object-Oriented Programming System)` is a programming technique that uses objects and classes to structure code in a way that is modular, reusable, and easier to maintain. The main concepts of OOPS include:

  1. **Class**: A blueprint for creating objects that defines the properties (attributes) and behaviors (methods) of the objects.
  2. **Object**: An instance of a class that encapsulates data and behavior related to that data, using single class multiple objects can be created.
  3. **Inheritance**: A mechanism that allows a new class (subclass) to inherit properties and behaviors from an existing class (superclass), promoting code reuse and establishing hierarchical relationships.
  4. **Polymorphism**: The term poly means many forms, it allows methods to do different things based on the type of methods passed to it, it can be achieved through method overloading and method overriding.
  5. **Encapsulation**: The practice of bundling data (attributes) and methods (functions) that operate on the data into a single unit (class), restricting direct access to some of the object's components.
  6. **Abstraction**: In OOPS, abstraction is the concept of hiding the complex implementation details suppose in a class there are multiple methods but we want to expose only few methods to the user, so that user can interact with the class without knowing the internal complexity.

## Design Principles

- Design principles are guidelines that help developers create software that is maintainable, scalable, and efficient. Some of the key design principles include:

  1. [**Single Responsibility Principle (SRP)**](./design-principle.md/#1-single-responsibility-principle-srp): A class should have only one reason to change, meaning it should only have one job or responsibility.
  2. [**Open/Closed Principle (OCP)**](./design-principle.md/#2-openclosed-principle-ocp): Software entities (classes, modules, functions) should be open for extension but closed for modification.
  3. [**Liskov Substitution Principle (LSP)**](./design-principle.md/#3-liskov-substitution-principle-lsp): Objects of a superclass should be replaceable with objects of a subclass without affecting the correctness of the program.
  4. [**Interface Segregation Principle (ISP)**](./design-principle.md/#4-interface-segregation-principle-isp): Clients should not be forced to depend on interfaces they do not use; instead, many specific interfaces are better than a single general-purpose interface.
  5. [**Dependency Inversion Principle (DIP)**](./design-principle.md/#5-dependency-inversion-principle-dip): High-level modules should not depend on low-level modules; both should depend on abstractions. Abstractions should not depend on details; details should depend on abstractions.
  6. [**DRY (Don't Repeat Yourself)**](./design-principle.md/#2-dry-principle-dont-repeat-yourself): Avoid code duplication by abstracting common functionality into reusable components.
  7. [**KISS (Keep It Simple, Stupid)**](./design-principle.md/#3-kiss-principle-keep-it-simple-stupid): Strive for simplicity in design and implementation, avoiding unnecessary complexity.
  8. [**YAGNI (You Aren't Gonna Need It)**](./design-principle.md/#3-yagni-principle-you-arent-gonna-need-it): Do not add functionality until it is necessary, focusing on current requirements rather than future possibilities.

## Design Patterns

- Design patterns are reusable solutions to common design problems that occur in software development. They provide a template for how to solve a problem in a way that has been proven to be effective. Some of the most commonly used design patterns include:

  1. [**Creational Patterns**](./design-pattern.md/#1-creation-patterns): Deal with object creation mechanisms, such as Singleton, Factory, Abstract Factory, Builder, and Prototype patterns.
  2. **Structural Patterns**: Deal with object composition and relationships, such as Adapter, Composite, Proxy, Flyweight, Facade, Bridge, and Decorator patterns.
  3. **Behavioral Patterns**: Deal with object interaction and responsibility distribution, such as Observer, Strategy, Command, Chain of Responsibility, Mediator, Memento, State, Template Method, Visitor, and Interpreter patterns.
