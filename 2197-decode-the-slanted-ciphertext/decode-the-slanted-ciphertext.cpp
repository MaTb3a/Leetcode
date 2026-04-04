class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int m = (encodedText.size())/rows,k=0;
        vector<string>v(rows);
        for(int i = 0 ; i < rows ;i++)
            for(int j = 0 ; j < m;j++)
                if(k < encodedText.size())
                    v[i].push_back(encodedText[k++]);
        
        string decodedText = "";
        for(int j = 0 ; j < m;j++){
            int i = 0,k = j;
            while(i < rows && k < m)decodedText+=v[i++][k++];
        }
        while(decodedText.size() && decodedText.back() == ' ')decodedText.pop_back();
        return decodedText;
    }
};