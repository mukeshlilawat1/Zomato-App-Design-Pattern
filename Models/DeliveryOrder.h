#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H

#include "Order.h"
using namespace std;

class DeliveryOrder : public Order {
    private:
      string userAddress;
    
    public:
      DeliveryOrder() {
        userAddress = "";
      }

      string getTypes() const override {
        return "Delivery";
      }

    //   getter and setter
    void setUserAddress(const string& addr) {
        userAddress = addr;
    }

    string getUserAddress() const {
        return userAddress;
    }
};

#endif 