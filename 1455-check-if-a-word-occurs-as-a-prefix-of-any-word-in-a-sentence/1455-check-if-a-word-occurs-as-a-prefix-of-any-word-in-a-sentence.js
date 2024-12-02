var isPrefixOfWord = function(sentence, searchWord) {
    const words = sentence.split(" ");
    for (let idx = 0; idx < words.length; idx++) {
        if (words[idx].startsWith(searchWord)) {
            return idx + 1; // Return 1-based index
        }
    }
    return -1;
};
