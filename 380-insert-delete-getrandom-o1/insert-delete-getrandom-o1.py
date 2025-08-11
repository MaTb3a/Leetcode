class RandomizedSet:
    lsts = []
    idxs = {}
    def __init__(self):
        self.lsts = []
        self.idxs = {}

    def insert(self, val: int) -> bool:
        if val in self.idxs:
            return False
        
        i = len(self.lsts)
        self.idxs[val] = i
        self.lsts.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val in self.idxs:
            i = self.idxs[val]
            j = len(self.lsts) -1
            updatedVal = self.lsts[j]
            self.lsts[i],self.lsts[j] = self.lsts[j],self.lsts[i]
            self.lsts.pop(-1)
            self.idxs[updatedVal] = i
            del self.idxs[val]
            return True
       
        return False

    def getRandom(self) -> int:
        sz = len(self.lsts)
        idx = random.randint(0,sz-1)
        return self.lsts[idx]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()