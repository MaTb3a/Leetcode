class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1_dic = {}
        for c in s1:
            if c in s1_dic:
                s1_dic[c]+=1
            else: s1_dic[c] = 1

        s2_dic = {}
        n = len(s1)
        m = len(s2)
        if n > m:
            return False
        for i in range(n):
            if s2[i] in s2_dic:
                s2_dic[s2[i]]+=1
            else: s2_dic[s2[i]] =1

        def check():
            for key,value in s1_dic.items():
                if key not in s2_dic or s2_dic[key] < value:
                    return False
            return True
        
        # print(s1_dic,s2_dic)
        if check():
            return True

        for i in range(n,m):
            if s2[i] in s2_dic:
                s2_dic[s2[i]]+=1
            else : s2_dic[s2[i]] = 1
            s2_dic[s2[i-n]]-=1
            if check():
                return True
        
        return False


