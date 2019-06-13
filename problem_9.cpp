
/**
 * Convert into an array of digits, then check if digits are palindrome
**/
class Solution {
public:
    bool isPalindrome(int l, int r, vector<int>& x_vec) {
        while (l >= 0 && r < x_vec.size()) {
            if (x_vec[l] != x_vec[r]) return false;
            l--;
            r++;
        }
        return true;
    }
    
    bool isPalindrome(int x) {
        if (x < 0) return false;
        vector<int> x_vec;
        while (x > 0) {
            int remainder = x % 10;
            x /= 10;
            x_vec.push_back(remainder);
        }
        
        if (x_vec.size() % 2 == 0) {
            int l = x_vec.size() / 2 - 1;
            int r = x_vec.size() / 2;
            return isPalindrome(l, r, x_vec);
        } else {
            int center = x_vec.size() / 2;
            return isPalindrome(center, center, x_vec);
        }
    }
};


/**
 * revert the number x, and check if the revert number is equal to x.
 * Be careful of bit numbers(INT_MAX)
**/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long multiplior = 1;
        long int revert_x = 0;
        int cp_x = x;
        while (cp_x >= 10) {
            cp_x /= 10;
            multiplior *= 10;
        }
        
        cp_x = x;
        while (cp_x > 0) {
            int remainder = cp_x % 10;
            cp_x /= 10;
            revert_x += remainder * multiplior;
            multiplior /= 10;
        }
        return x == revert_x;
    }
};

/**
    test cases:
    1. 0 // 0 is special 
    2. 9 // test if the number only have 1 digit
    // test numbers with even digits
    3. 10 
    4. 11
    // test numbers with odd digits
    5. 121
    6. 122 
    7. -11 // negative
    8. 2147483647 // large numbe
**/