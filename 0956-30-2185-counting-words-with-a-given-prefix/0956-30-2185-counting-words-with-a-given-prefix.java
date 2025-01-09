class TrieNode {
    TrieNode[] children = new TrieNode[26];
    int frq = 0;
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
            node.frq++;
        }
    }

    private int search(String prefix) {
        TrieNode node = trie;
        for (char ch : prefix.toCharArray()) {
            int index = ch - 'a';
            if (node.children[index] == null) {
                return 0;
            }
            node = node.children[index];
        }
        return node.frq;
    }

    public int prefixCount(String[] words, String pref) {
        for (String word : words) {
            insert(word);
        }
        return search(pref);
    }
}
