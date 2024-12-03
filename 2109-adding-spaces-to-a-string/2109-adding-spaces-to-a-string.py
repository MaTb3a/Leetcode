class Solution:
    def addSpaces(self, s: str, spaces: list[int]) -> str:
        result = []
        space_set = set(spaces)
        
        for i, char in enumerate(s):
            if i in space_set:
                result.append(" ")
            result.append(char)
        
        return "".join(result)
