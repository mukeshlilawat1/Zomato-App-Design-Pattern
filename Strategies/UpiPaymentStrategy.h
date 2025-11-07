#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class UpiPaymentStrategy : public PaymentStrategy {
private:
    string mobile;

public:
    UpiPaymentStrategy(const string &mobile) {
        this->mobile = mobile;
    }

    void pay(double amount) override {
        cout<<"Payment " << amount << "Using UPI ( " << mobile << " ) " << endl;
    }
};

#endif
