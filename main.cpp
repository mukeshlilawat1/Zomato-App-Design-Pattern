#include<iostream>
#include "ZomatoApp.h"
using namespace std; 

int main(int argc, char const *argv[])
{
    // Create TomatoApp Object
    ZomatoApp* zomato_app = new ZomatoApp();

    // Simulate a user coming in (Happy Flow)
    User* user = new User(101, "lilawat", "Delhi");
    cout << "User: " << user->getName() << " is active." << endl;

    // User searches for restaurants by location
    vector<Restaurant*> restaurantList = zomato_app->searchRestaurants("Delhi");

    if (restaurantList.empty()) {
        cout << "No restaurants found!" << endl;
        return 0;
    }
    cout << "Found Restaurants:" << endl;
    for (auto restaurant : restaurantList) {
        cout << " - " << restaurant->getName() << endl;
    }

    // User selects a restaurant
    zomato_app->selectRestaurant(user, restaurantList[0]);

    cout << "Selected restaurant: " << restaurantList[0]->getName() << endl;

    // User adds items to the cart
    zomato_app->addToCart(user, "P1");
    zomato_app->addToCart(user, "P2");

    zomato_app->printUserCart(user);

    // User checkout the cart
    Order* order = zomato_app->checkoutNow(user, "Delivery", new UpiPaymentStrategy("97979894649"));

    // User pay for the cart. If payment is success, notification is sent.
    zomato_app->payForOrder(user, order);

    // Cleanup Code.
    delete zomato_app;
    delete user;

    return 0;
}