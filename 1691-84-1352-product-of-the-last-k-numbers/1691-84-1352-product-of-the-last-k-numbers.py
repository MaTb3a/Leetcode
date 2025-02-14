class ProductOfNumbers:
    def __init__(self):
        self.v = [1]

    def add(self, num: int) -> None:
        if num == 0:
            self.v = [1]
        else:
            self.v.append(self.v[-1] * num)

    def getProduct(self, k: int) -> int:
        return 0 if len(self.v) <= k else self.v[-1] // self.v[-1 - k]

# Example Usage:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)
