class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        istringstream ss1(sentence1);
        vector<string>v1 ((istream_iterator<string>(ss1)),istream_iterator<string>());
        istringstream ss2(sentence2);
        vector<string>v2 ((istream_iterator<string>(ss2)),istream_iterator<string>());

        int l = 0, r1 = v1.size() -1 , r2 = v2.size() -1; 
        while( l <= r1 && l<= r2  && v1[l] == v2[l])l++;
        while(r1 > -1 && r2 > -1 && v1[r1] == v2[r2])r1--,r2--;

        return l > r1 || l > r2;
     
    }
};