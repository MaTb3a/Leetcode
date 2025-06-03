class Solution(object):
    def maxCandies(self, status, candies, keys, containedBoxes, initialBoxes):
        foundOpenable = True
        totalCandies = 0
        while initialBoxes and foundOpenable:
            foundOpenable = False
            nextBoxes = []
            for boxId in initialBoxes:
                if status[boxId]:
                    foundOpenable = True
                    nextBoxes.extend(containedBoxes[boxId])
                    for keyId in keys[boxId]:
                        status[keyId] = 1
                    totalCandies += candies[boxId]
                else:
                    nextBoxes.append(boxId)
            initialBoxes = nextBoxes
        return totalCandies