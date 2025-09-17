#include <iostream>
#include <vector>

using namespace std;

enum class PaymentMode {
    PayPal = 0,
    GooglePay = 1,
    CreditCard = 2,
    Unknown = 3
};

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

void checkout(PaymentMode mode, double amount) {
    // Pointing to the funtion
    static const vector<void(*)(double)> handlers = {
        processPayPal,
        processGooglePay,
        processCreditCard
    };

    int index = static_cast<int>(mode);
    if (index >= 0 && index < (int)handlers.size()) {
        handlers[index](amount);
    } else {
        processUnknown(amount);
    }
}

int main() {
    double amount = 150.75;

    checkout(PaymentMode::PayPal, amount);
    checkout(PaymentMode::GooglePay, amount);
    checkout(PaymentMode::CreditCard, amount);
    checkout(PaymentMode::Unknown, amount);

    return 0;
}
