class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        def check(root,word):
            cnt = 0
            for i in range(0,len(root)):
                if root[i] == word[i]:
                    cnt+=1
            return cnt == len(root)
        dictionary.sort()
        ans = ""
        cur = ""
        sentence+=(' ')
        for ch in sentence :
            if ch != ' ':
                cur+=(ch)
            else:
                for root in dictionary:
                    if len(root) < len(cur) and check(root,cur):
                        cur = root
                        break
                ans+=cur+' '
                cur=''
        ans = ans[:len(cur)-1]
        return ans