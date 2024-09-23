struct TrieNode {
    TrieNode* child[26]; // 'c' - 'a'
    bool isWord;
};
class Solution {
public:
    
    int dp[51];
    int solve(int idx,string &s, TrieNode* &trie){
        if(idx == s.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int op1 = solve(idx+1,s,trie)+1;
        int op2 = INT_MAX;
        // for(string word : dictionary){
        //     if(s.find(word,idx) == idx)
        //         op2 = min(op2,solve(idx+word.size(),s,dictionary));
        // }
        auto node = trie;
        for(int j = idx ; j < s.size();j++){
             if(!node->child[s[j]-'a'])
                break;
              node = node->child[s[j]-'a'];
              if(node->isWord)
                op2 = min(op2,solve(j+1,s,trie));
        }
        return dp[idx] = min(op1,op2);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp,-1,sizeof dp);

        TrieNode* trie = new TrieNode();

        for(string word : dictionary){
            auto node = trie;
            for(char ch : word){
                if(!node->child[ch-'a'])
                    node->child[ch-'a'] = new TrieNode();
                node = node->child[ch-'a'];
            }
            node->isWord = true;
        }
        return solve(0,s,trie);
    }
};