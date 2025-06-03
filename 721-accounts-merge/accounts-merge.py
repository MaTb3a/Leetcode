class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        adj = defaultdict(set)
        email_to_name = {}

        for account in accounts:
            name = account[0]
            first_email = account[1]
            for email in account[1:]:
                adj[first_email].add(email)
                adj[email].add(first_email)
                email_to_name[email] = name
            
        
        vis = set()
        ans = []

        def dfs(email,emails):
            if email in vis:
                return
            vis.add(email)
            emails.append(email)
            for ch in adj[email]:
                dfs(ch,emails)
        
        for email in adj:
            if email not in vis:
                emails = []
                dfs(email,emails)
                ans.append([email_to_name[email]] + sorted(emails))
                
        return ans