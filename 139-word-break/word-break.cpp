struct TrieNode {
    bool tail = false;
    TrieNode *child[26];
}*trie;
class Solution {
public:
    void insert(string s){
        TrieNode *top = trie;
        for(char ch : s){
            if(!top->child[ch-'a'])
                top->child[ch-'a'] = new TrieNode();
            top = top->child[ch-'a'];
        }
        top->tail = true;
    }

    bool search(string s){
        TrieNode *top = trie;
        for(char ch : s){
            if(!top->child[ch-'a'])
                return false;
            top = top->child[ch-'a'];
        }
        return top->tail;
    }
    int dp[303][303];
    int solve(int i,int len,int n,string &s){
        if(i >= n)return 1;
        if(i + len > n)return false;
        
        int &ret = dp[i][len];
        if(~ret)return ret;
        ret = 0;
        ret=max(ret,solve(i,len+1,n,s));

        if(search(s.substr(i,len)))
            ret=max(ret,solve(i+len,1,n,s));
        return ret;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        trie = new TrieNode();

        for(auto s : wordDict){
            insert(s);
        }
        memset(dp,-1,sizeof dp);
        return solve(0,1,s.size(),s);

    }
};