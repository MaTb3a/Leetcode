
var findAllRecipes = function(recipes, ingredients, supplies) {
    const adj = new Map();
    const inDegree = new Map();
    
    for (const recipe of recipes) {
        inDegree.set(recipe, 0);
    }
    
    for (let i = 0; i < recipes.length; i++) {
        for (const ingredient of ingredients[i]) {
            if (!adj.has(ingredient)) {
                adj.set(ingredient, []);
            }
            adj.get(ingredient).push(recipes[i]);
            inDegree.set(recipes[i], inDegree.get(recipes[i]) + 1);
        }
    }
    
    const ans = [];
    
    while (supplies.length > 0) {
        const node = supplies.pop();
        if (adj.has(node)) {
            for (const recipe of adj.get(node)) {
                inDegree.set(recipe, inDegree.get(recipe) - 1);
                if (inDegree.get(recipe) === 0) {
                    supplies.push(recipe);
                    ans.push(recipe);
                }
            }
        }
    }
    
    return ans;

};