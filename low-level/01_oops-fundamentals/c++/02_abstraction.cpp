// 🟡 Abstraction, mean giving the simple method to perform a process.
// 🟡 While hiding complex logic behind it, so the end user can use it without worrying about internal details.

#include <iostream>
#include <memory>

class PaymentGateWay {
   public:
    virtual void sendMoney(int amount) = 0;
    virtual ~PaymentGateWay()          = default;
};

class RazerpayGateway : public PaymentGateWay {
   public:
    void sendMoney(int amount) override {
        std::cout << "Paid " << amount << " via razer pay" << std::endl;
    }
};

class StripGateway : public PaymentGateWay {
   public:
    void sendMoney(int amount) override {
        std::cout << "Paid " << amount << " via strip pay" << std::endl;
    }
};

class Payment {
   private:
    std::unique_ptr<PaymentGateWay> paymentGateway;

   public:
    Payment(std::unique_ptr<PaymentGateWay> g) : paymentGateway(std::move(g)) {}

    void send(int amount) {
        paymentGateway->sendMoney(
            amount);  // Payment class don't have any idea which gate is behind it.
    }
};

int main() {
    // Payment via RazerPay
    Payment payment(std::make_unique<RazerpayGateway>());
    payment.send(500);

    // Payment via Stripe
    Payment stripPayment(std::make_unique<StripGateway>());
    payment.send(1000);

    return 0;
}
