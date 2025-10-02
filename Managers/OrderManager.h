#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include <vector>
#include<iostream>
#include "../Models/Order.h"
using namespace std;

class OrderManager {
    private:
      vector<Order *> orders;
      static OrderManager* instance;

      OrderManager() {
        // private constructor
      }

     public:
     static OrderManager* getInstance() {
        if (!instance)
        {
            instance = new OrderManager();
        
        }
        return instance;  
     }

     void addOrder(Order* order) {
        orders.push_back(order);
     }

     void listOrders() {
        cout << "\n --- All Orders ---" << endl;
        for (auto order: orders)
        {
           cout << order->getTypes() << "order for " << order->getUser()->getName()
           << " | Total: " << order->getTotal()
            << "| At: " << order->getScheduled() << endl;
        }
        
     }
};

OrderManager* OrderManager::instance = nullptr;

#endif //order manager h