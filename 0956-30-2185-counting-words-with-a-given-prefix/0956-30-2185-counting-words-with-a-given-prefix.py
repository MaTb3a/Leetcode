class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.frq = 0

class Solution:
    def __init__(self):
        self.trie = TrieNode()

    def insert(self, word):
        node = self.trie
        for ch in word:
            index = ord(ch) - ord('a')
            if not node.children[index]:
                node.children[index] = TrieNode()
            node = node.children[index]
            node.frq += 1

    def search(self, prefix):
        node = self.trie
        for ch in prefix:
            index = ord(ch) - ord('a')
            if not node.children[index]:
                return 0
            node = node.children[index]
        return node.frq

    def prefixCount(self, words, pref):
        for word in words:
            self.insert(word)
        return self.search(pref)
