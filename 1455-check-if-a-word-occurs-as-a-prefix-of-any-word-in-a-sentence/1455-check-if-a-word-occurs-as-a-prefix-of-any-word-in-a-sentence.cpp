class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int idx = 1;
        for(int i = 0 ; i < sentence.size();i++){
            int j = 0;
            while(j < searchWord.size() && searchWord[j] == sentence[i])i++,j++;
            if(j == searchWord.size())return idx;
            while(i < sentence.size() && sentence[i]!=' ')i++;
            idx++;
        }
        return -1;
    }
};