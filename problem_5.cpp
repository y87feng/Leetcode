
// Brute Force
class Solution {
public:
    string longestPalindrome(string s) {
        for (int j = s.length(); j >= 0; j--) {
            for (int i = 0; i <= s.length() - j; i++) {
                string substr = s.substr(i, j);
                if (checkPalindrome(substr)) {
                    return substr;
                }
            }
        }
        return "";
    }
    
    bool checkPalindrome(string str) {
        for (int i = 0; i < str.length() / 2; i++) {
            if (str[i] != str[str.length()-1-i]) return false;
        }
        
        return true;
    }
};

// Dynamic Programming
class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length()));
        for (int i = 0; i < s.length(); i++) {
            dp[i][i] = true;
            if (dp[i][i]) res = 1 > res.length() ? s.substr(i,1) : res;
            if (i + 1 < s.length()) {
                dp[i][i+1] = s[i] == s[i+1];
                if (dp[i][i+1]) res = s.substr(i,2);
            }
        }
        
        for (int length = 1; length <= s.length(); length++) { // length
            for (int i = 0; i < s.length(); i++) { // start index
                int j = i + length - 1; // end index
                if (i - 1 >= 0 && j + 1 < s.length()) {
                    dp[i-1][j+1] = dp[i][j] && s[i-1] == s[j+1];
                    if (dp[i-1][j+1]) {
                        int new_len = (j+1) - (i-1) + 1;
                        res = new_len > res.length() ? s.substr(i-1,new_len) : res;
                    }
                }
            }
        }
        
        return res;
    }
};

// another way to use DP without using extra space

class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            string palin1 = expand(i-1, i + 1,s);
            string palin2 = expand(i, i + 1,s);
            res = res.length() <= palin1.length() ? palin1 : res;
            res = res.length() <= palin2.length() ? palin2 : res;
        }
        
        return res;
    }
    
    string expand(int start, int end, string s) {
        while (start >= 0 && end < s.length()) {
            if (s[start] == s[end]) {
                start--;
                end++;
            }
            else return s.substr(start+1, end - (start + 1));
        }
        return s.substr(start+1, end - (start + 1));
    }
};