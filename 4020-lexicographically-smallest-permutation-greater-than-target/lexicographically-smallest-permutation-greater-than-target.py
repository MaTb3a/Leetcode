class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        cnt = [0] * 26

        for ch in s:
            cnt[ord(ch) - ord('a')] += 1

        for ch in target:
            cnt[ord(ch) - ord('a')] -= 1

        for i in range(len(target) - 1, -1, -1):
            cur = ord(target[i]) - ord('a')
            cnt[cur] += 1

            if any(x < 0 for x in cnt):
                continue

            nxt = -1
            for c in range(cur + 1, 26):
                if cnt[c]:
                    nxt = c
                    break

            if nxt == -1:
                continue

            cnt[nxt] -= 1

            ans = list(target[:i])
            ans.append(chr(nxt + ord('a')))

            for c in range(26):
                ans.extend(chr(c + ord('a')) * cnt[c])

            return ''.join(ans)

        return ""