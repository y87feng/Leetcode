class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        int start_ind = 0;
        int max_len = 0;
        vector<int> checkTable(128, -1);
        
        for (int i = 0; i < s.length(); i++) {
            if (checkTable[s[i]] >= start_ind) { // duplicate
                start_ind = checkTable[s[i]] + 1;
            }
            checkTable[s[i]] = i; // update latest index
            max_len = max(max_len, i - start_ind + 1);
            
        }
        return max_len;
    }
};