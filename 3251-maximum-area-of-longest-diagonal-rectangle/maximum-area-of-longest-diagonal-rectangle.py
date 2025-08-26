class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        mxDignoal,mxArea = 0,0
        for i in range(len(dimensions)):
            d = sqrt(dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1])
            if d > mxDignoal:
                mxArea = dimensions[i][0] * dimensions[i][1]
                mxDignoal = d
            if d == mxDignoal:
                mxArea = max(mxArea,dimensions[i][0] * dimensions[i][1])

        return mxArea
