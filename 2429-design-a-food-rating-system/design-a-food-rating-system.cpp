class FoodRatings {
public:
    map<string,set<pair<int,string>>>mp;

    map<string,int>currentRate;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0 ; i < foods.size();i++){
            mp[cuisines[i]].insert({-ratings[i],foods[i]});
            currentRate[foods[i]] = -ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
         pair<int,string> p = {currentRate[food],food};
          for(auto &it : mp){
            if(it.second.find(p) != it.second.end()){
                it.second.erase(p);
                it.second.insert({-newRating,food});
                currentRate[food] = -newRating;
            }
          }
    }
    
    string highestRated(string cuisine) {
        return (*(mp[cuisine].begin())).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */