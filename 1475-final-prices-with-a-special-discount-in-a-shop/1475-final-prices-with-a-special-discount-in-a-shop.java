import java.util.*;

class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        Stack<Integer> stack = new Stack<>();
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && stack.peek() > prices[i]) {
                stack.pop();
            }
            int tmp = prices[i];
            if (!stack.isEmpty()) {
                prices[i] -= stack.peek();
            }
            stack.push(tmp);
        }
        return prices;
    }
}
