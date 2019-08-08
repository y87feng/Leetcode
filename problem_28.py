class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        for inx, s in enumerate(haystack):
            if len(haystack) - inx < len(needle):
                break
            match = True
            for n_inx, pattern in enumerate(needle):
                if haystack[n_inx + inx] != needle[n_inx]:
                    match = False
                    break
            if match:
                return inx
        return -1


if __name__ == "__main__":
    s = Solution()
    print(s.strStr("!23", "23"))
