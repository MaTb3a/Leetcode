class TrieNode {
    constructor() {
        this.children = {};
        this.freq = 0;
    }
}

var stringMatching = function(words) {
    const trie = new TrieNode();

    const insert = (word) => {
        let node = trie;
        for (const ch of word) {
            if (!node.children[ch]) {
                node.children[ch] = new TrieNode();
            }
            node = node.children[ch];
            node.freq++;
        }
    };

    const get = (word) => {
        let node = trie;
        for (const ch of word) {
            node = node.children[ch];
        }
        return node.freq > 1;
    };

    for (const word of words) {
        for (let j = 0; j < word.length; j++) {
            insert(word.substring(j));
        }
    }

    const result = [];
    for (const word of words) {
        if (get(word)) {
            result.push(word);
        }
    }

    return result;
};
