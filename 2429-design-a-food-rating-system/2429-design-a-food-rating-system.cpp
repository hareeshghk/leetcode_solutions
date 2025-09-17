class FoodRatings {
    unordered_map<string, set<pair<int, string>>> store;
    unordered_map<string, string> foodCuisineMap;
    unordered_map<string, int> currentRating;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            currentRating[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            store[cuisines[i]].insert(pair<int, string>(-1 * ratings[i], foods[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        int curr = currentRating[food];
        string cuisine = foodCuisineMap[food];

        store[cuisine].erase(pair<int, string>(-1 * curr, food));
        store[cuisine].insert(pair<int, string>(-1 * newRating, food));
        currentRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return store[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */