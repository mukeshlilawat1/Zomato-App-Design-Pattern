//
// Created by mukes on 07-11-2025.
//

#ifndef  ORDER_FACTORY_H
#define  ORDER_FACTORY_H

#include  "../Models/Order.h"
#include  "../Models/Cart.h"
#include  "../Models/Restaurant.h"
#include "../Strategies/PaymentStrategy.h"
#include <vector>
#include <string>
using namespace  std;

class OrderFactory {
public:
    virtual Order* createOrder(User* user, Cart* cart, Restaurant* restaurant,  const vector<MenuItem>&menu_items,
        PaymentStrategy* payment_strategy, double totalCost, const string& orderType) = 0;

    virtual ~OrderFactory(){}
};



#endif  //ZOMATO_APP_DESIGN_PATTERN_ORDER_FACTORY_H

