class Spreadsheet:
    def __init__(self, rows: int):
        self.cells = defaultdict(int)

    def setCell(self, cell: str, value: int) -> None:
        self.cells[cell] = value

    def resetCell(self, cell: str) -> None:
        self.cells[cell] = 0

    def convert(self,s):
        if s.isdigit():
            return int(s)
        else:
            return int(self.cells[s])

    def getValue(self, formula: str) -> int:
        vals = formula[1:].split('+')
        return self.convert(vals[0])+self.convert(vals[1])
        


# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)