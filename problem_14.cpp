class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if (strs.size() == 0) return res;
        res = strs[0];
        for (string & s : strs) {
            res = res.substr(0, min(res.length(), s.length())); // truncate
            for (int i = 0; i < res.length(); i++) {
                if (s[i] != res[i]) {
                    res = res.substr(0,i);
                    break;
                } 
            }
        }
        return res;
    }
};

/**
 * Tests:
 * 1. empty array
 * 2. array with 1 element
 * 3. at some time the length of res is larger than the length of str[i] with index i
**/