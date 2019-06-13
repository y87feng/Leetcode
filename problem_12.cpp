/**
 * Logic problem: try to find the pattern to reduce the lines of the code
**/

class Solution {
    vector<vector<string>> dic = {{"I", "V", "X"}, 
    {"X", "L", "C"}, 
    {"C", "D", "M"}, {"M", "", ""}};
public:
    string intToRoman(int num) {
        string res;
        // int dividor = 10;
        int digits = 0;
        while (num > 0) {
            int remainder = num % 10;
            if (remainder == 4) res = dic[digits][0] + dic[digits][1] + res; 
            else if (remainder == 9) res = dic[digits][0] + dic[digits][2] + res;
            else if (remainder < 4) {
                while (remainder > 0) {
                    res = dic[digits][0] + res;
                    remainder--;
                }
            }
            else if (remainder < 9) {
                remainder -= 5;
                while (remainder > 0) {
                    res = dic[digits][0] + res;
                    remainder--;
                }
                res = dic[digits][1] + res;
            }
            digits++;
            num /= 10;
        }
        return res;
    }
};

/**
 * Test: 
 * 0, 1-3,4,5-8,9
**/