class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0,n = s.size();
        while(i < n){
            while(i < n &&  s[i]== ' ')i++;
            while(i < n && s[i] != ' ') s[j++] = s[i++];
            s[j] = ' ';j++;
        }
        while(s.size() >= j || s.back() == ' ')s.pop_back();
        reverse(s.begin(),s.end());
        
        i = 0;
        n = s.size();
        while (i < n){
            int j = i;
            while( j < n && s[j] !=' ')j++;
            int jump = j;
            j--;
            while(i < j){
                swap(s[i],s[j]);
                i++;j--;
            }
            i = jump+1;
        }
        return s;
    }
};