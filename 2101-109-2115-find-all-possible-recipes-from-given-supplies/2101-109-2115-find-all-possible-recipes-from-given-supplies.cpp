class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>>adj;
        unordered_map<string,int>inDegree;
        
        for(int i = 0 ; i < recipes.size();i++)
            for(string ingreident : ingredients[i])
                adj[ingreident].push_back(recipes[i]),inDegree[recipes[i]]++;

        vector<string>ans;
        while(supplies.size()){
            string node = supplies.back();
            supplies.pop_back();
            for(string recipe : adj[node]){
                inDegree[recipe]--;
                if(!inDegree[recipe]){
                    supplies.push_back(recipe);
                    ans.push_back(recipe);
                }
            }
        }
        return ans;
    }
};