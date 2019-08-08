class Solution:
    def countAndSay(self, n: int) -> str:
        res = '1'
        if n == 1:
            return res
        iter = 1
        while iter <= n:
            prev = ""
            count = 0
            tmp = ""
            for inx, char in enumerate(res):
                if char == prev:
                    count += 1
                else:
                    tmp += str(count) + prev
                    count = 1
                    prev = char
            tmp += str(count) + prev
            res = tmp
            iter += 1
        return res
