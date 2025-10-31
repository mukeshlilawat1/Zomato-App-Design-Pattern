#ifndef NOW_ORDER_FACTORY_H
#define NOW_ORDER_FACTORY_H

#include "OrderFactory.h"
#include "../Models/DeliveryOrder.h"
#include "../Models/PickupOrder.h"
#include "../Utils/TimeUtiles.h"


class NowOrderFactory : public OrderFactory {
    public:
     Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuItem>&menuItems, 
                        PaymentStrategy* paymentStrategy, double totalCost, const string& orderType) override {
                            Order* order = nullptr;
                            if(orderType == "Delivery"){
                                auto deliveryOrder = new DeliveryOrder();
                                deliveryOrder->setUserAddress(user->getAddress());
                                order = deliveryOrder;
                            } else {
                                auto pickupOrder = new PickupOrder();
                                pickupOrder->setRestaurantAddress(restaurant->getLocation());
                                order = pickupOrder;
                            
                            }

                            order->setUser(user);
                            order->setRestaurant(restaurant);
                            order->setItems(menuItems);
                            order->setPaymentStrategy(paymentStrategy);
                            order->setScheduled(TimeUtils::getCurrentTime());
                            order->setTotal(totalCost);
                            return order;
                        }

}

#endif 