class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        adj = {}
        inDegree = {}
        for i in range(len(recipes)):
            inDegree[recipes[i]] = (len(ingredients[i]))
            for ingredient in ingredients[i]:
                if ingredient not in adj:
                    adj[ingredient] = []
                adj[ingredient].append(recipes[i])
                
        ans = []
        while len(supplies):
            node = supplies.pop()
            if node not in adj:
                continue
            for recipe in adj[node]:
                inDegree[recipe]-=1
                if inDegree[recipe] == 0:
                    supplies.append(recipe)
                    ans.append(recipe)
                    
        return ans