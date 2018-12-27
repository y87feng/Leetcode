class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int index = 0;
        bool neg = false;
        while (index < str.length()) {
            if (str[index] == ' ') index++;
            else break;
        }
        if (str[index] == '-') {
            neg = true;
            index++;
        } else if (str[index] == '+') {
            neg = false;
            index++;
        }
        
        for (int i = index; i < str.length(); i ++) {
            if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
            {
                res *= 10;
                res += str[i] - '0';
                if (neg) {
                    if (-res < INT_MIN) return INT_MIN;
                } else {
                    if (res > INT_MAX) return INT_MAX;
                }
            }
            else break; // word
        }
        
        return neg ? -res : res;
    }
};