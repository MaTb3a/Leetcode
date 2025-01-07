import java.util.*;

class TrieNode {
    TrieNode[] children = new TrieNode[26];
    int freq = 0;
}

class Solution {
    private TrieNode trie;

    public Solution() {
        this.trie = new TrieNode();
    }

    private void insert(String word) {
        TrieNode node = trie;
        for (char ch : word.toCharArray()) {
            int index = ch - 'a';
            if (node.children[index] == null) {
                node.children[index] = new TrieNode();
            }
            node = node.children[index];
            node.freq++;
        }
    }

    private boolean get(String word) {
        TrieNode node = trie;
        for (char ch : word.toCharArray()) {
            node = node.children[ch - 'a'];
        }
        return node.freq > 1;
    }

    public List<String> stringMatching(String[] words) {
        for (String word : words) {
            for (int j = 0; j < word.length(); j++) {
                insert(word.substring(j));
            }
        }

        List<String> result = new ArrayList<>();
        for (String word : words) {
            if (get(word)) {
                result.add(word);
            }
        }

        return result;
    }
}
