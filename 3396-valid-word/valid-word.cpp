class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'u' || ch == 'o';
    }
    bool isValid(string word) {
        if(word.size() < 3)return false;
        bool vowel = false,consonant = false;
        for(char c : word){
            if((!isdigit(c)) && (!isalpha(c)))return false;
            if(isdigit(c))continue;
            vowel |= isVowel(tolower(c));
            consonant |= !isVowel(tolower(c));
        }
        return vowel & consonant;

    }
};