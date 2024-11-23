import java.util.ArrayList;
import java.util.List;

class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int n = box.length;
        int m = box[0].length;

        char[][] rotatedBox = new char[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotatedBox[i][j] = '.';
            }
        }

        for (int i = 0; i < n; i++) {
            int lastStone = m - 1;
            for (int j = m - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    lastStone = j - 1;
                    rotatedBox[j][n - i - 1] = '*';
                } else if (box[i][j] == '#') {
                    rotatedBox[lastStone][n - i - 1] = '#';
                    lastStone--;
                }
            }
        }

        return rotatedBox;
    }
}
