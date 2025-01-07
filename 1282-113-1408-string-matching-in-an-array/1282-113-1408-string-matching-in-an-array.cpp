class Solution {
public:
    struct Trie{
        Trie* vis[26];
        int frq = 0;
    }*trie;

    void insert(string s){
        Trie * top = trie;
        for(char ch : s){
            if(!top->vis[ch-'a'])
                top->vis[ch-'a'] = new Trie();
            top = top->vis[ch-'a'];
            top->frq++;
        }
    }
    bool get(string s){
        Trie* top = trie;
        for(char ch : s)
            top = top->vis[ch-'a'];
        
        return top->frq > 1;
    }

    vector<string> stringMatching(vector<string>& words) {
        trie = new Trie();
        for(int i = 0 ; i < words.size();i++)
            for(int j = 0 ; j < words[i].size();j++)
                insert(words[i].substr(j));
        
            
        vector<string>v;
        for(int i = 0 ; i < words.size();i++)
            if(get(words[i]))v.push_back(words[i]);
        
        return v;
    }
};