
/** 
 * solution 1:
 * prepare a 2D-panel and put the string in the panel by zigzag.
 * Finally, combine them from top to down
**/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        vector<string> zigzag(numRows);
        bool increase = true;
        for (int i = 0, row = 0; i < s.length(); i++) {
            zigzag[row] += s[i];
            if (increase) {
                if (row == numRows-1) {
                    increase = false;
                    row -= 1; 
                } else {
                    row++;
                }
            } else {
                if (row == 0) {
                    increase = true;
                    row = 1;
                } else {
                    row--;
                }
            }
        }
        
        string res;
        for (int i = 0; i < zigzag.size(); i++) {
            res += zigzag[i];
        }
        return res;
    }
};


/** 
 * Solution 2:
 * Conclude a pattern for ZigZagConversion, For all whole numbers k:
 * Characters in row 0 are located at indexes k(2⋅numRows−2)
 * Characters in row \text{numRows}-1numRows−1 are located at indexes k(2⋅numRows−2)+numRows−1
 * Characters in inner row ii are located at indexes k(2⋅numRows−2)+i and (k+1)(2⋅numRows−2)−i.
**/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        string res;
        for (int row = 0; row < numRows; row++) {
            int index = row;
            bool go_up = false;
            int old_inx = -1;
            for (; index < s.length();) {
                if (old_inx != index) res += s[index];
                old_inx = index;
                if (!go_up) {
                    index += (numRows-1-row) * 2;
                } else {
                    index += row * 2;
                }
                go_up = !go_up;
            }
        }
        return res;
    }
};

/**
 * Consider Test cases:
 * String:
 * 1. empty string
 * 2. string length is less that column num
 * 3. string length is greater than or equal to column num
 * 
 * Column:
 * 1. column is 0
 * 2. column is 1
 * 3. column is greater than 1
**/