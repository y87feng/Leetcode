class Solution {
    unordered_map<char, string> table = {{'2', "abc"},
        {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"},
        {'9', "wxyz"}};
    public:
    vector<string> letterCombinations(string digits) {
        // the digits doesn't contain 0, 1, *, #

        vector<string> res;

        if(digits.length() == 0) return res;
        DFS(res, digits, 0, "");
        return res;
    }

    void DFS(vector<string>& res, string& digits, int index, string res_s) {
        if (index == digits.length()) {
            res.push_back(res_s);
            return;
        }

        for (char c : table[digits[index]]) {
            DFS(res, digits, index+1, res_s+c);
        }
    }
};

class Solution {
    unordered_map<char, string> table = {{'2', "abc"},
        {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"},
        {'9', "wxyz"}};
    public:
    vector<string> letterCombinations(string digits) {
        // the digits doesn't contain 0, 1, *, #
        vector<string> res;
        if (digits.length() == 0) return res;
        
        res.push_back("");
        for (char c : digits) {
            vector<string> temp;
            for (string s : res) {
                for (char letter : table[c]) {
                    temp.push_back(s + letter);
                }
            }
            res = move(temp);
        }
        return res;
    }

};