import java.util.*;

class ProductOfNumbers {
    private List<Integer> v;

    public ProductOfNumbers() {
        v = new ArrayList<>();
        v.add(1);
    }

    public void add(int num) {
        if (num == 0) {
            v.clear();
            v.add(1);
        } else {
            v.add(v.get(v.size() - 1) * num);
        }
    }

    public int getProduct(int k) {
        return v.size() <= k ? 0 : v.get(v.size() - 1) / v.get(v.size() - 1 - k);
    }
}

/**
 * Example Usage:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */
