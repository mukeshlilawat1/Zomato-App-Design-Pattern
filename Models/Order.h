#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Restaurant.h"
#include "MenuItem.h"
#include "../Strategies/PaymentStrategy.h"
#include "../Utils/TimeUtiles.h"
using namespace std;

class Order
{
protected:
    static int nextOrderId;
    int OrderId;
    User *user;
    Restaurant *restaurant;
    vector<MenuItem> items;
    PaymentStrategy *paymentStrategy;
    double total;
    string scheduled;

public:
    Order()
    {
        user = nullptr;
        restaurant = nullptr;
        paymentStrategy = nullptr;
        total = 0.0;
        OrderId = ++nextOrderId;
    }

    virtual ~Order()
    {
        delete paymentStrategy;
    }

    bool proccessPayment()
    {
        if (paymentStrategy)
        {
            paymentStrategy->pay(total);
            return true;
        }
        else
        {
            cout << "Please choose a payment mode firs : t" << endl;
            return false;
        }
    }

    virtual string getTypes() const = 0;

    // Getter and setters
    int getOrderId() const
    {
        return OrderId;
    }

    void setUser(User *u)
    {
        user = u;
    }

    User *getUser() const
    {
        return user;
    }

    void setRestaurant(Restaurant *r)
    {
        restaurant = r;
    }

    Restaurant *getRestaurant() const
    {
        return restaurant;
    }

    void setItems(const vector<MenuItem> &its)
    {
        items = its;
        total = 0;
        for (auto &i : items)
        {
            total += i.getPrice();
        }
    }

    const vector<MenuItem> &getItems() const
    {
        return items;
    }

    void setPaymentStrategy(PaymentStrategy *p)
    {
        paymentStrategy = p;
    }

    void setScheduled(const string &s)
    {
        scheduled = s;
    }

    string getScheduled() const
    {
        return scheduled;
    }

    double getTotal() const
    {
        return total;
    }

    void setTotal(int total)
    {
        this->total = total;
    }
};

int Order::nextOrderId = 0;
#endif