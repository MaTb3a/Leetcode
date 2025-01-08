from collections import defaultdict

class TrieNode:
    def __init__(self):
        self.child = defaultdict(TrieNode)
        self.frq = 0

class Solution:
    def __init__(self):
        self.trie = TrieNode()

    def insert(self, s):
        node = self.trie
        n = len(s)
        for i in range(n):
            pre, suf = s[i], s[n - i - 1]
            node = node.child[(pre, suf)]
            node.frq += 1

    def search(self, s):
        node = self.trie
        n = len(s)
        for i in range(n):
            pre, suf = s[i], s[n - i - 1]
            if (pre, suf) not in node.child:
                return 0
            node = node.child[(pre, suf)]
        return node.frq

    def countPrefixSuffixPairs(self, words):
        count = 0
        for word in reversed(words):
            count += self.search(word)
            self.insert(word)
        return count
