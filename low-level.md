# Low Level System Design

> **Low level system design** is the process of designing the internal components and architecture of a software system by using pre-define principles and patterns. It focuses on the detailed implementation of individual modules, classes, and functions, ensuring that they work together efficiently to meet the overall system requirements.

- [Low Level System Design](#low-level-system-design)
  - [Key Concepts](#key-concepts)
  - [OOPS Concepts](#oops-concepts)
  - [Design Principles](#design-principles)
    - [1. SOLID Principles](#1-solid-principles)
      - [1. Single Responsibility Principle (SRP)](#1-single-responsibility-principle-srp)
      - [2. Open/Closed Principle (OCP)](#2-openclosed-principle-ocp)
      - [3. Liskov Substitution Principle (LSP)](#3-liskov-substitution-principle-lsp)
      - [4. Interface Segregation Principle (ISP)](#4-interface-segregation-principle-isp)
      - [5. Dependency Inversion Principle (DIP)](#5-dependency-inversion-principle-dip)
    - [2. DRY Principle (Don't Repeat Yourself)](#2-dry-principle-dont-repeat-yourself)
    - [3. KISS Principle (Keep It Simple, Stupid)](#3-kiss-principle-keep-it-simple-stupid)
    - [3. YAGNI Principle (You Aren't Gonna Need It)](#3-yagni-principle-you-arent-gonna-need-it)

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

### 1. SOLID Principles

- **SOLID** Principles are a set of five design principles that help create maintainable and scalable software systems. They are:
  1. **Single Responsibility Principle (SRP)**
  2. **Open/Closed Principle (OCP)**
  3. **Liskov Substitution Principle (LSP)**
  4. **Interface Segregation Principle (ISP)**
  5. **Dependency Inversion Principle (DIP)**

#### 1. Single Responsibility Principle (SRP)

- It says that a class should have only one responsibility or reason to change. This means that a class should only have one job or function.
- Imagine, A backer who is bake the bread, that job is to bake high quality bread, ensure equality of the bread while baking, this is best example of single responsibility principle. Because a baker could have other responsibilities like managing the inventory, handling customer orders, etc. But if we follow SRP, we would create separate classes for each of these responsibilities.
- Example:

  ```javascript
  // Class for baking bread
  class BreadBaker {
    bakeBread() {
      console.log("Baking high-quality bread...");
    }
  }

  // Class for managing inventory
  class InventoryManager {
    manageInventory() {
      console.log("Managing inventory...");
    }
  }

  // Class for ordering supplies
  class SupplyOrder {
    orderSupplies() {
      console.log("Ordering supplies...");
    }
  }

  // Class for serving customers
  class CustomerService {
    serveCustomer() {
      console.log("Serving customers...");
    }
  }

  // Class for cleaning the bakery
  class BakeryCleaner {
    cleanBakery() {
      console.log("Cleaning the bakery...");
    }
  }

  function main() {
    const baker = new BreadBaker();
    const inventoryManager = new InventoryManager();
    const supplyOrder = new SupplyOrder();
    const customerService = new CustomerService();
    const cleaner = new BakeryCleaner();

    // Each class focuses on its specific responsibility
    baker.bakeBread();
    inventoryManager.manageInventory();
    supplyOrder.orderSupplies();
    customerService.serveCustomer();
    cleaner.cleanBakery();
  }

  main();
  ```

#### 2. Open/Closed Principle (OCP)

- This principle states that software entities (classes, modules, functions, etc.) should be open for extension (adding new functionality) but closed for modification (existing code should not be changed).
- For example, consider a payment processing system that initially supports only credit card payments. If we want to add support for PayPal payments, we should be able to do so without modifying the existing credit card payment code.

- Example: Game character attack using OCP:

  ```cpp
  #include <iostream>

  class Character {
  public:
      virtual int attack() = 0;
  };

  class Soldier : public Character {
  public:
      int attack() override {
          return 50;
      }
  };

  class Archer : public Character {
  public:
      int attack() override {
          return 30;
      }
  };

  class Game {
    public:
    // Fun fact: Following function follows DIP as well, because Game class depends on abstraction(Character) not on concrete classes(Soldier, Archer)
      void performAttack(Character* character) {
          int damage = character->attack();
          std::cout << "Character attacks with damage: " << damage << std::endl;
      }
  }

  int main() {
      Game game;

      Character* soldier = new Soldier();
      game.performAttack(soldier);

      Character* archer = new Archer();
      game.performAttack(archer);

      delete soldier;
      delete archer;

      return 0;
  }
  ```

  ```javascript
  // ❌ Bad Example: Violating OCP
  class PaymentProcessor {
    processPayment(paymentType, amount) {
      if (paymentType === "creditCard") {
        console.log(`Processing credit card payment of $${amount}`);
      } else if (paymentType === "paypal") {
        console.log(`Processing PayPal payment of $${amount}`);
      }
    }
  }
  // ✅ Good Example: Following OCP
  class PaymentProcessor {
    processPayment(paymentMethod, amount) {
      paymentMethod.pay(amount);
    }
  }

  class CreditCardPayment {
    pay(amount) {
      console.log(`Processing credit card payment of $${amount}`);
    }
  }

  class PayPalPayment {
    pay(amount) {
      console.log(`Processing PayPal payment of $${amount}`);
    }
  }

  function main() {
    const paymentProcessor = new PaymentProcessor();

    const creditCardPayment = new CreditCardPayment();
    paymentProcessor.processPayment(creditCardPayment, 100);

    const payPalPayment = new PayPalPayment();
    paymentProcessor.processPayment(payPalPayment, 200);
  }

  // OR --> Using interface
  interface PaymentMethod {
    pay(amount: number): void;
  }

  class CreditCardPayment implements PaymentMethod {
    pay(amount: number): void {
      console.log(`Processing credit card payment of $${amount}`);
    }
  }

  class PayPalPayment implements PaymentMethod {
    pay(amount: number): void {
      console.log(`Processing PayPal payment of $${amount}`);
    }
  }

  function main() {
    const paymentProcessor = new PaymentProcessor();

    const creditCardPayment = new CreditCardPayment();
    paymentProcessor.processPayment(creditCardPayment, 100);

    const payPalPayment = new PayPalPayment();
    paymentProcessor.processPayment(payPalPayment, 200);
  }
  ```

#### 3. Liskov Substitution Principle (LSP)

- This principle states that objects of a superclass should be replaceable with objects of a subclass without affecting the correctness of the program. In other words, subclasses should be able to stand in for their parent classes without causing unexpected behavior.
- For example, consider a class `Bird` with a method `fly()`. If we have a subclass `Penguin` that cannot fly, substituting a `Penguin` object for a `Bird` object would violate LSP.
- It could seems similar to OCP but they are different,
  - **OCP** is about extending behavior without modifying existing code.
  - **LSP** is about ensuring that subclasses can be used interchangeably with their parent classes without causing issues.
- Example: Shapes area calculation using LSP:

  ```python
  from abc import ABC, abstractmethod

  class Shape(ABC):
      @abstractmethod
      def area(self):
          pass

  class Rectangle(Shape):
      def __init__(self, width, height):
          self.width = width
          self.height = height

      def area(self):
          return self.width * self.height

  class Circle(Shape):
      def __init__(self, radius):
          self.radius = radius

      def area(self):
          return 3.14 * self.radius * self.radius
  ```

- Example: Bird class violating LSP

  ```java
  // ❌ Bad Example: Violating LSP
  class Bird {
      void fly() {
          System.out.println("Flying");
      }
  }

  class Sparrow extends Bird {
      // Sparrow can fly
  }

  class Penguin extends Bird {
      @Override
      void fly() {
          throw new UnsupportedOperationException("Penguins cannot fly");
      }
  }

  public class Main {
      public static void main(String[] args) {
          Bird myBird = new Penguin();
          myBird.fly(); // This will throw an exception
      }
  }
  ```

  ```cpp
  // ✅ Good Example: Following LSP
  #include <iostream>

  class Bird {
    public:
      virtual void makeSound() = 0;
  };

  class Sparrow : public Bird {
    public:
      void makeSound() override {
          std::cout << "Chirp Chirp" << std::endl;
      }
  };

  class Penguin : public Bird {
    public:
      void makeSound() override {
          std::cout << "Honk Honk" << std::endl;
      }
  };

  int main() {
      Bird* myBird1 = new Sparrow();
      myBird1->makeSound(); // Outputs: Chirp Chirp

      Bird* myBird2 = new Penguin();
      myBird2->makeSound(); // Outputs: Honk Honk

      delete myBird1;
      delete myBird2;

      return 0;
  }
  ```

#### 4. Interface Segregation Principle (ISP)

- This is the first principle that applies to interfaces not to classes. It states that no client should be forced to implement which is irrelevant to them. In other words, interfaces should be specific to the clients that use them, rather than being general-purpose.
- For example, consider an interface `Animal` with methods `fly()`, `swim()`, and `walk()`. A class `Dog` that implements this interface would be forced to provide implementations for all three methods, even though dogs cannot fly or swim. To follow ISP, we should create separate interfaces for each behavior.
- Example: ISP in action with different interfaces for different behaviors:

  ```cpp
  // ❌ Bad Example: Violating ISP
  class UserActions {
    public:
      virtual void placeOrder() = 0;
      virtual void cookFood() = 0;
      virtual void deliverOrder() = 0;
      virtual void manageUsers() = 0;
  };

  // ✅ Good Example: Following ISP
  class OrderPlacer {
    public:
      virtual void placeOrder() = 0;
  };

  class FoodCooker {
    public:
      virtual void cookFood() = 0;
  };

  class OrderDeliverer {
    public:
      virtual void deliverOrder() = 0;
  };

  class UserManager {
    public:
      virtual void manageUsers() = 0;
  };
  ```

#### 5. Dependency Inversion Principle (DIP)

- The principle states that high-level modules should not depend on low-level modules. Both should depend on abstractions (e.g., interfaces). Additionally, abstractions should not depend on details; details should depend on abstractions.
- For example, consider a class `ReportGenerator` that depends on a concrete class `PDFExporter` to generate reports in PDF format. To follow DIP, we should introduce an abstraction (interface) `Exporter` that both `ReportGenerator` and `PDFExporter` depend on. This way, we can easily switch to a different exporter (e.g., `ExcelExporter`) without modifying the `ReportGenerator` class.

- Example: DIP in action with abstraction for exporting reports:

  ```cpp
  #include <iostream>

  class Exporter {
    public:
      virtual void exportReport(const std::string& data) = 0;
  };

  class PDFExporter : public Exporter {
    public:
      void exportReport(const std::string& data) override {
          std::cout << "Exporting report as PDF: " << data << std::endl;
      }
  };

  class ExcelExporter : public Exporter {
    public:
      void exportReport(const std::string& data) override {
          std::cout << "Exporting report as Excel: " << data << std::endl;
      }
  };

  class ReportGenerator {
    private:
      Exporter* exporter;
    public:
      ReportGenerator(Exporter* exp) : exporter(exp) {}

      void generateReport(const std::string& data) {
          // Generate report logic
          exporter->exportReport(data);
      }
  };

  int main() {
      Exporter* pdfExporter = new PDFExporter();
      ReportGenerator reportGen1(pdfExporter);
      reportGen1.generateReport("Annual Financial Report");

      Exporter* excelExporter = new ExcelExporter();
      ReportGenerator reportGen2(excelExporter);
      reportGen2.generateReport("Monthly Sales Report");

      delete pdfExporter;
      delete excelExporter;

      return 0;
  }
  ```

- Example: Scrapper using DIP, We have two website to scrape data from, instead of "Data Extractor" class depending on concrete classes "WebsiteAScraper" and "WebsiteBScraper", it depends on abstraction "Scraper" interface.

  ```typescript
  // Scraper interface
  interface DataExtractor {
    extractData(html: any): string;
    formatData(data: string): string;
    validateData(data: string): boolean;
  }

  // Concrete implementation for Website A
  class WebsiteADataExtractor implements DataExtractor {
    extractData(html: any): string {
      // Logic to extract data from Website A's HTML
      return "Data from Website A";
    }

    formatData(data: string): string {
      // Logic to format data for Website A
      return `Formatted ${data}`;
    }

    validateData(data: string): boolean {
      // Logic to validate data for Website A
      return true;
    }
  }

  class WebsiteBDataExtractor implements DataExtractor {
    extractData(html: any): string {
      // Logic to extract data from Website B's HTML
      return "Data from Website B";
    }

    formatData(data: string): string {
      // Logic to format data for Website B
      return `Formatted ${data}`;
    }

    validateData(data: string): boolean {
      // Logic to validate data for Website B
      return true;
    }
  }

  // Data Scraper class depending on abstraction
  class Scrapper {
    private extractor: DataExtractor;

    constructor(extractor: DataExtractor) {
      this.extractor = extractor;
    }

    scrape(html: any): void {
      const data = this.extractor.extractData(html);
      const formattedData = this.extractor.formatData(data);
      if (this.extractor.validateData(formattedData)) {
        console.log("Scraped and validated data:", formattedData);
      } else {
        console.log("Data validation failed.");
      }
    }
  }
  ```

- Example: Computer connect with different peripherals using DIP

  ```cpp
  #include <iostream>

  // Abstraction for Peripheral
  class Peripheral {
    public:
      virtual void connect() = 0;
  };

  // Concrete implementation for Keyboard
  class Keyboard : public Peripheral {
    public:
      void connect() override {
          std::cout << "Keyboard connected." << std::endl;
      }
  };

  // Concrete implementation for Mouse
  class Mouse : public Peripheral {
    public:
      void connect() override {
          std::cout << "Mouse connected." << std::endl;
      }
  };


  // Computer class depending on abstraction
  class Computer {
    private:
      Peripheral* peripheral;
    public:
      Computer(Peripheral* p) : peripheral(p) {}

      void connectPeripheral() {
          peripheral->connect();
      }
  };

  int main() {
      Peripheral* keyboard = new Keyboard();
      Computer computer1(keyboard);
      computer1.connectPeripheral();

      Peripheral* mouse = new Mouse();
      Computer computer2(mouse);
      computer2.connectPeripheral();

      delete keyboard;
      delete mouse;

      return 0;
  }
  ```

  - It does not have to know about the concrete classes, it just depends on the abstraction `Peripheral` interface.

### 2. DRY Principle (Don't Repeat Yourself)

- The DRY principle states that every piece of knowledge or logic should have a single, unambiguous representation within a system. In other words, you should avoid duplicating code or logic in multiple places. Instead, you should encapsulate it in a single location and reuse it whenever needed.
- For example, consider a scenario where you have a function that calculates the area of a rectangle. If you need to calculate the area of a rectangle in multiple parts of your code, you should create a single function for this calculation and call it whenever needed, rather than duplicating the area calculation logic in each place.
- Example: DRY principle in action with a function to calculate area:

  ```python
  # ❌ Bad Example: Violating DRY
  def calculate_area_rectangle(length, width):
      return length * width

  def calculate_area_square(side):
      return side * side

  def calculate_area_circle(radius):
      return 3.14 * radius * radius

  # ✅ Good Example: Following DRY
  def calculate_area_rectangle(length, width):
      return length * width

  def calculate_area_square(side):
      return calculate_area_rectangle(side, side)

  def calculate_area_circle(radius):
      return 3.14 * radius * radius
  ```

### 3. KISS Principle (Keep It Simple, Stupid)

- The KISS principle emphasizes the importance of simplicity in design and implementation. It suggests that systems should be kept as simple as possible, avoiding unnecessary complexity and over-engineering. Simple designs are easier to understand, maintain, and modify.
- For example, when designing a user interface, it's better to have a clean and straightforward layout with essential features rather than a cluttered interface with too many options and features that may confuse users.

- Example: KISS principle in action with a function to find the maximum number in an array:

  ```go

  // ❌ Bad Example: Violating KISS
  func findMax(arr []int) int {
      max := arr[0]
      for i := 1; i < len(arr); i++ {
          if arr[i] > max {
              max = arr[i]
          }
      }
      return max
  }

  // ✅ Good Example: Following KISS
  func findMax(arr []int) int {
      sort.Ints(arr)
      return arr[len(arr)-1]
  }
  ```

- Example: KISS principle in action with a simple function to calculate the sum of two numbers:

  ```javascript
  // ❌ Bad Example: Violating KISS
  function calculateSum(arr) {
    let sum = 0;
    for (let i = 0; i < arr.length; i++) {
      sum += arr[i];
    }
    return sum;
  }

  // ✅ Good Example: Following KISS
  function calculateSum(a, b) {
    return a + b;
  }
  ```

- Example: KISS principle in action with a simple user authentication function:

  ```python
  # ❌ Bad Example: Violating KISS
  def authenticate_user(username, password):
      if username == "admin" and password == "admin123":
          return True
      elif username == "user" and password == "user123":
          return True
      else:
          return False

  # ✅ Good Example: Following KISS
  def authenticate_user(username, password):
      valid_credentials = {
          "admin": "admin123",
          "user": "user123"
      }
      return valid_credentials.get(username) == password
  ```

### 3. YAGNI Principle (You Aren't Gonna Need It)

- The YAGNI principle states that you should not add functionality or features to a system until they are actually needed. This means that you should avoid implementing features based on assumptions about future requirements, as this can lead to unnecessary complexity and wasted effort.
- For example, if you're developing a web application and you think that users might want to upload profile pictures in the future, you shouldn't implement this feature until there is a clear requirement for it. Instead, focus on delivering the core functionality first.
- Example: YAGNI principle in action with a simple user registration function:

  ```javascript
  // ❌ Bad Example: Violating YAGNI
  function registerUser(username, password, profilePicture) {
    // Logic to register user
    console.log(
      `User ${username} registered with profile picture: ${profilePicture}`
    );
  }

  // ✅ Good Example: Following YAGNI
  function registerUser(username, password) {
    // Logic to register user
    console.log(`User ${username} registered`);
  }
  ```

- Example: YAGNI principle in action with a simple shopping cart function:

  ```python
  # ❌ Bad Example: Violating YAGNI
  class ShoppingCart:
      def __init__(self):
          self.items = []
          self.discount_code = None  # Unused feature
      def add_item(self, item):
          self.items.append(item)
      def apply_discount(self, code):
          self.discount_code = code  # Unused feature

  # ✅ Good Example: Following YAGNI
  class ShoppingCart:
      def __init__(self):
          self.items = []
      def add_item(self, item):
          self.items.append(item)
  ```

- Example: YAGNI principle in action with a simple blog post function:

  ```cpp
  // ❌ Bad Example: Violating YAGNI
  class BlogPost {
    private:
      std::string title;
      std::string content;
      std::string tags; // Unused feature
    public:
      BlogPost(std::string t, std::string c) : title(t), content(c) {}
      void display() {
          std::cout << "Title: " << title << std::endl;
          std::cout << "Content: " << content << std::endl;
      }
  };

  // ✅ Good Example: Following YAGNI
  class BlogPost {
    private:
      std::string title;
      std::string content;
    public:
      BlogPost(std::string t, std::string c) : title(t), content(c) {}
      void display() {
          std::cout << "Title: " << title << std::endl;
          std::cout << "Content: " << content << std::endl;
      }
  };
  ```
