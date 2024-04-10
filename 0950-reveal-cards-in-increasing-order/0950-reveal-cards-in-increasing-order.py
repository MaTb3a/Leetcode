class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        indexOfDeck = 0
        indexOfAns = 0
        n = len(deck)
        state = True
        ans = [0] * n
        deck.sort()
        while indexOfDeck < n:
            if ans[indexOfAns] == 0:
                if state:
                    ans[indexOfAns] = deck[indexOfDeck]
                    indexOfDeck+=1
                state = not state
            indexOfAns+=1
            if indexOfAns == n:
                indexOfAns = 0
        return ans
            
                
        
        