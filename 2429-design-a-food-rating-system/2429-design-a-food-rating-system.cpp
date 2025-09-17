class FoodRatings {
    unordered_map<string, pair<string, int>> foodToCuisineRating;
    unordered_map<string, map<int, set<string>>> cusineToRatingFoodSetMap;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            foodToCuisineRating[foods[i]] = {cuisines[i], {ratings[i]}};
            cusineToRatingFoodSetMap[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        auto foodInfo = foodToCuisineRating.find(food);
        int currRating = foodInfo->second.second;
        string cuisine = foodInfo->second.first;

        foodInfo->second.second = newRating;

        cusineToRatingFoodSetMap[cuisine][currRating].erase(food);

        if (cusineToRatingFoodSetMap[cuisine][currRating].size() == 0) {
            cusineToRatingFoodSetMap[cuisine].erase(currRating);
        }

        cusineToRatingFoodSetMap[cuisine][newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
        return *(cusineToRatingFoodSetMap[cuisine].rbegin()->second.begin());
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */