class Solution {
    unordered_map<char, char> table = {{'}', '{'}, {')', '('}, {']', '['}};
    unordered_set<char> left = {'{', '(', '['};
public:
    bool isValid(string s) {
        stack<char> cache;
        for (char c : s) {
            if (left.find(c) != left.end()) {
                cache.push(c);
            } else {
                if (cache.empty() || table[c] != cache.top()) {
                    return false;
                } else {
                    cache.pop();
                }
            }
        }
        return cache.empty();
    }
};