#include <iostream>
#include <vector>

using namespace std;

enum PaymentModeID {
    PayPal = 0,
    GooglePay = 1,
    CreditCard = 2
};

using PaymentHandler = void(*)(double);

void processPayPal(double amount) {
    cout << "Processing PayPal payment of $" << amount << endl;
}

void processGooglePay(double amount) {
    cout << "Processing GooglePay payment of $" << amount << endl;
}

void processCreditCard(double amount) {
    cout << "Processing Credit Card payment of $" << amount << endl;
}

void processUnknown(double amount) {
    cout << "Invalid payment mode selected!" << endl;
}

// Global vector with default handler initially
vector<PaymentHandler> paymentHandlers = { processUnknown };

// Register handler and auto-fill missing slots with default handler
void registerHandler(PaymentModeID id, PaymentHandler handler) {
    if (id >= paymentHandlers.size()) {
        paymentHandlers.resize(id + 1, processUnknown);
    }
    paymentHandlers[id] = handler;
}

void checkout(int modeId, double amount) {
    paymentHandlers[modeId](amount);
}

int main() {
    registerHandler(PayPal, processPayPal);
    registerHandler(GooglePay, processGooglePay);
    registerHandler(CreditCard, processCreditCard);

    double amount = 150.75;

    checkout(PayPal, amount);
    checkout(GooglePay, amount);
    checkout(CreditCard, amount);
    checkout(99, amount);  // safely calls processUnknown

    return 0;
}
