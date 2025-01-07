class TrieNode:
    def __init__(self):
        self.children = {}
        self.freq = 0

class Solution:
    def __init__(self):
        self.trie = TrieNode()

    def insert(self, word):
        node = self.trie
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
            node.freq += 1

    def get(self, word):
        node = self.trie
        for ch in word:
            node = node.children[ch]
        return node.freq > 1

    def stringMatching(self, words: list[str]) -> list[str]:
        for word in words:
            for j in range(len(word)):
                self.insert(word[j:])
        
        result = []
        for word in words:
            if self.get(word):
                result.append(word)
        
        return result
