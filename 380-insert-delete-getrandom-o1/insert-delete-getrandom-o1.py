class RandomizedSet:

    def __init__(self):
        self.lst = []
        self.idxes = {}

    def insert(self, val: int) -> bool:
        if val in self.idxes:
            return False

        self.lst.append(val) 
        self.idxes[val] = len(self.lst) -1
        return True
    
    def remove(self, val: int) -> bool:
        if val not in self.idxes:
            return False
        
        i = self.idxes[val] 
        last_val = self.lst[-1]

        self.lst[i] = last_val
        self.idxes[last_val] = i

        self.lst.pop(-1)
        del self.idxes[val]
        return True


    def getRandom(self) -> int:
        return random.choice(self.lst)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()