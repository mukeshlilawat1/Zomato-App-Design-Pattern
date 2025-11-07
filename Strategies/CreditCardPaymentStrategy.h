//
// Created by mukes on 07-11-2025.
//

#ifndef CREDIT_CARD_PAYMENT_STRATEGY_H
#define CREDIT_CARD_PAYMENT_STRATEGY_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class CreditCardPaymentStrategy : public PaymentStrategy {
private:
    string CardNumber;

public:
    CreditCardPaymentStrategy(const string & card) {
        CardNumber = card;
    }

    void pay(double amount) override {
        cout << "Paid " << amount << "using credit card ( " << CardNumber << " ) " << endl;
    }
};


#endif  //ZOMATO_APP_DESIGN_PATTERN_CREADIT_CARD_PAYMENT_STRATEGY_H