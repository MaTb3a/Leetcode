struct TrieNode{
    TrieNode* child[26];
    int frq =0;
}*trie;

class Solution {
public:
    void insert(string &s){
        TrieNode* top = trie;
        for(char ch : s){
            if(!top->child[ch-'a'])
                top->child[ch-'a'] = new TrieNode();
            top = top->child[ch-'a'];
            top->frq++;
        }
    }
    int search(string &s){
        TrieNode* top = trie;
        for(char ch : s){
            if(!top->child[ch-'a'])
                return 0;
            top = top->child[ch-'a'];
        }
        return top->frq;
    }
    int prefixCount(vector<string>& words, string pref) {
         trie = new TrieNode();
         for(string word : words)
            insert(word);
        return search(pref);
    }
};