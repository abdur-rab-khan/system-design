// 🟡 Polymorphism means the same method can behave differently — either because a child class overrides it (like different enemies having their own attack()), or because the same method name is reused with different parameters (like add() taking 2 or 3 numbers).

#include <format>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class NotificationSystem {
   public:
    virtual void send()           = 0;
    virtual ~NotificationSystem() = default;
};

class EmailNotificationSystem : public NotificationSystem {
   private:
    std::string email;
    std::string body;
    std::string subject;

   public:
    EmailNotificationSystem(std::string email, std::string body, std::string subject)
        : email(email), body(body), subject(subject) {}

    void send() override {
        std::cout << std::format("[SEND BY EMAIL] {} - {} - {}", email, subject, body) << std::endl;
    }
};

class SMSNotificationSystem : public NotificationSystem {
   private:
    std::string message;
    std::string phoneNumber;

   public:
    SMSNotificationSystem(std::string phoneNumber, std::string message)
        : message(message), phoneNumber(phoneNumber) {}

    void send() override {
        std::cout << std::format("[SEND BY SMS] {} - {}", phoneNumber, message) << std::endl;
    }
};

class PushNotificationSystem : public NotificationSystem {
   private:
    std::string sender;
    std::string receiver;

   public:
    PushNotificationSystem(std::string sender, std::string receiver)
        : sender(sender), receiver(receiver) {}

    void send() override {
        std::cout << std::format("[PUSH NOTIFICATION] {} - {}", sender, receiver) << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<NotificationSystem>> notifications;
    notifications.push_back(std::make_unique<EmailNotificationSystem>("a@x.com", "Hi", "Welcome!"));
    notifications.push_back(
        std::make_unique<SMSNotificationSystem>("9999999999", "Your OTP is 1234"));
    notifications.push_back(std::make_unique<PushNotificationSystem>("Server", "User123"));

    for (auto& n : notifications) {
        n->send();  // same call, different behavior — this line IS the polymorphism
    }
    return 0;
}
