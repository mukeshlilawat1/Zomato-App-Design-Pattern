#ifndef ZOMATO_APP_H
#define ZOMATO_APP_H

#include<vector>
#include<string>
#include "Models/User.h"
#include "Models/Restaurant.h"
#include "Models/Cart.h"
#include "Managers/RestaurantManager.h"
#include "Managers/OrderManager.h"
#include "Strategies/PaymentStrategy.h"
#include "Strategies/UpiPaymentStrategy.h"
#include "Factories/NowOrderFactory.h"
#include "Factories/ScheduledOrderFactory.h"
#include "Services/NotifcationService.h"
#include "Utils/TimeUtiles.h"
using namespace std;

class ZomatoApp {
    public:
    ZomatoApp() {

    }

    void initializeRestaurants() {
        
    }
}