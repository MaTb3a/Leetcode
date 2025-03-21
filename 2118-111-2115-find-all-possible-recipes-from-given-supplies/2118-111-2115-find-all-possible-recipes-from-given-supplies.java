class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        Map<String, List<String>> adj = new HashMap<>();
        Map<String, Integer> inDegree = new HashMap<>();
        
        for (String recipe : recipes) {
            inDegree.put(recipe, 0);
        }
        
        for (int i = 0; i < recipes.length; i++) {
            for (String ingredient : ingredients.get(i)) {
                adj.putIfAbsent(ingredient, new ArrayList<>());
                adj.get(ingredient).add(recipes[i]);
                inDegree.put(recipes[i], inDegree.get(recipes[i]) + 1);
            }
        }
        
        List<String> ans = new ArrayList<>();
        List<String> suppliesList = new ArrayList<>(Arrays.asList(supplies));
        
        while (!suppliesList.isEmpty()) {
            String node = suppliesList.remove(suppliesList.size() - 1);
            if (adj.containsKey(node)) {
                for (String recipe : adj.get(node)) {
                    inDegree.put(recipe, inDegree.get(recipe) - 1);
                    if (inDegree.get(recipe) == 0) {
                        suppliesList.add(recipe);
                        ans.add(recipe);
                    }
                }
            }
        }
        
        return ans;
    }
    
}