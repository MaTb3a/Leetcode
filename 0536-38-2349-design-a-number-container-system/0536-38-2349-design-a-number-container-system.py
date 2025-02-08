from collections import defaultdict
import sortedcontainers

class NumberContainers:
    def __init__(self):
        self.index_to_number = {}
        self.number_to_indices = defaultdict(sortedcontainers.SortedSet)

    def change(self, index: int, number: int) -> None:
        if index in self.index_to_number:
            old_number = self.index_to_number[index]
            self.number_to_indices[old_number].discard(index)
            if not self.number_to_indices[old_number]:
                del self.number_to_indices[old_number]

        self.index_to_number[index] = number
        self.number_to_indices[number].add(index)

    def find(self, number: int) -> int:
        return next(iter(self.number_to_indices[number]), -1)
