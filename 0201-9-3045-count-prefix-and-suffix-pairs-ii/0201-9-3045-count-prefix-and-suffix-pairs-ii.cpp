struct TrieNode{
    map<pair<char,char>,TrieNode*>child;
    int frq = 0;
}*trie;
class Solution {
public:
    void insert(string s){
        TrieNode* top = trie;
        int n = s.size();
        for(int i = 0 ;  i < n;i++){
            char pre = s[i], suf = s[n-i-1];
            if(!top->child[{pre,suf}]) top->child[{pre,suf}] = new TrieNode();
            top = top->child[{pre,suf}];
            top->frq++;
        }
    }
    long long search(string s){
        TrieNode* top = trie;
        int n = s.size();
        for(int i = 0 ;  i < n;i++){
            char pre = s[i], suf = s[n-i-1];
            if(!top->child[{pre,suf}]) return 0;
            top = top->child[{pre,suf}];
        }
        return top->frq;
    }
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long cnt = 0;
        trie = new TrieNode();
        for(int i = words.size() - 1 ; i >= 0 ; i--){
            cnt+=search(words[i]);
            insert(words[i]);
        }
        return cnt;

    }
};