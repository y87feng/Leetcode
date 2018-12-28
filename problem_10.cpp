class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length() +1, vector<bool>(p.length() + 1));
        dp[0][0] = true;
        if (p.length() > 0 && p[0] == '*') return false; // special case
        
        // initialize
        for (int i = 1; i <= p.length(); i++) {
            if (p[i-1] == '*') {
                dp[0][i] = dp[0][i-2];
            }
        }
        
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= p.length(); j++) {
                if (p[j - 1] != '*') {
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                } else {
                    dp[i][j] = dp[i][j-2] || // .* zero character
                        dp[i-1][j] && (s[i - 1] == p[j - 2] || p[j-2] == '.');
                        
                }
            }
        }
        
        return dp[s.length()][p.length()];
    }
};


// Memory optimization: Space complexity: O(m) m is the length of string p
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(2, vector<bool>(p.length() + 1));
        dp[0][0] = true;
        if (p.length() > 0 && p[0] == '*') return false; // special case
        
        // initialize
        for (int i = 1; i <= p.length(); i++) {
            if (p[i-1] == '*') {
                dp[0][i] = dp[0][i-2];
            }
        }
        
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= p.length(); j++) {
                if (p[j - 1] != '*') {
                    dp[1][j] = dp[0][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                } else {
                    dp[1][j] = dp[1][j-2] || // .* zero character
                        dp[0][j] && (s[i - 1] == p[j - 2] || p[j-2] == '.');
                }
            }
            
            for (int j = 0; j <= p.length(); j++) {
                dp[0][j] = dp[1][j];
            }
        }
        
        return dp[0][p.length()];
    }
};