import java.util.*;

class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder result = new StringBuilder();
        Set<Integer> spaceSet = new HashSet<>();
        for (int space : spaces) {
            spaceSet.add(space);
        }

        for (int i = 0; i < s.length(); i++) {
            if (spaceSet.contains(i)) {
                result.append(" ");
            }
            result.append(s.charAt(i));
        }

        return result.toString();
    }
}
