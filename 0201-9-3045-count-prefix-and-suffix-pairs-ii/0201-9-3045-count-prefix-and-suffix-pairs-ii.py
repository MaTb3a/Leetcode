class TrieNode:
    def __init__(self):
        self.child = {}
        self.frq = 0

class Solution:
    def __init__(self):
        self.trie = TrieNode()

    def insert(self, s):
        top = self.trie
        n = len(s)
        for i in range(n):
            pre = s[i]
            suf = s[n - i - 1]
            if (pre, suf) not in top.child:
                top.child[(pre, suf)] = TrieNode()
            top = top.child[(pre, suf)]
            top.frq += 1

    def search(self, s):
        top = self.trie
        n = len(s)
        for i in range(n):
            pre = s[i]
            suf = s[n - i - 1]
            if (pre, suf) not in top.child:
                return 0
            top = top.child[(pre, suf)]
        return top.frq

    def countPrefixSuffixPairs(self, words):
        cnt = 0
        for word in reversed(words):
            cnt += self.search(word)
            self.insert(word)
        return cnt
