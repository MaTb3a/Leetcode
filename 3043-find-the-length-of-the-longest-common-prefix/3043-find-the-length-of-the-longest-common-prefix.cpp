struct TrieNode{
    TrieNode* child[10];
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* trie = new TrieNode();
        for(int x : arr1){
            string s = to_string(x);
            TrieNode* node = trie;
            for(char ch : s){
                int idx = ch - '0';
                if(!node->child[idx])
                    node->child[idx] = new TrieNode();
                node = node->child[idx];
            }
        }
        int ans = 0;

          for(int x : arr2){
            string s = to_string(x);
            TrieNode* node = trie;
            int len = 0;
            for(char ch : s){
                int idx = ch - '0';
                if(!node->child[idx])
                   break;
                node = node->child[idx];
                len++;
                ans = max(ans,len);
            }
        }
        return ans;
    }
};