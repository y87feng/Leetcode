/**
 * find the pattern
**/

class Solution {
    map<char,int> dict = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
    {'C', 100}, {'D', 500}, {'M',1000}};
    map<char,char> special = {{'V','I'}, {'X', 'I'}, {'L', 'X'}, {'C', 'X'},
    {'D', 'C'}, {'M', 'C'}};
    map<string, int> special_v = {{"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90},
    {"CD", 400}, {"CM", 900}};
public:
    int romanToInt(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i != s.length()-1) {
                if (special[s[i+1]] == s[i]) {
                    string spec;
                    spec += s[i];
                    spec += s[i+1];
                    res += special_v[spec];
                    i++;
                    continue;
                }
            }
            res += dict[s[i]];
        }
        return res;
    }
};

/**
 * Test: 
 * 0, 1-3,4,5-8,9
**/