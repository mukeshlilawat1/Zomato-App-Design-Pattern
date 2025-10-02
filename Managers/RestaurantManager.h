#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include<vector>
#include<string>
#include<algorithm>
#include "../Models/Restaurant.h"
using namespace std;

class RestaurantManager {
    private:
     vector<Restaurant*> restaurants;
     static RestaurantManager* instance;

     RestaurantManager() {
        // private constructor
     }

    public:
       static RestaurantManager* getInstance() {
        if (!instance)
        {
           instance = new RestaurantManager();
        }
        return instance;
       } 

       void addRestaurant(Restaurant* r) {
        restaurants.push_back(r);
       }

       vector<Restaurant*>searchByLocation(string location) {
                 vector<Restaurant*>result;
                 transform(location.begin(), location.end(), location.begin(), ::tolower);
                 for(auto restaurantss :restaurants) {
                    string r1 = restaurantss->getLocation();
                    transform(r1.begin(), r1.end(), r1.begin(), ::tolower);

                    if (r1 == location)
                    {
                       result.push_back(restaurantss);
                    }
                 }
                 return result;
                }
};

RestaurantManager* RestaurantManager::instance = nullptr;

#endif //RESTAURANT_MANAGER_H