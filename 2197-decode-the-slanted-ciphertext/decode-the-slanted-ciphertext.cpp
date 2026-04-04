class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int m = encodedText.size()/rows;       
        string s = "";
        for(int j = 0 ; j < m;j++){
            int i = 0,k = j;
            while(i < rows && k < m)s+=encodedText[m*i+++k++];
        }
        while(s.size() && s.back() == ' ')s.pop_back();
        return s;
    }
};