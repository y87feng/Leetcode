/**
 * Brute Force, try the permutation of two heights
**/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i+1; j < height.size(); j++) {
                maxArea = max(maxArea, (j-i) * min(height[i], height[j]));
            }
        }
        return maxArea;
    }
};

/**
 * Using two pointers,
 *     Start from the leftmost height and rightmost height, with largest width
 *     Then, we move one of columns to inward, and the width will decrease
 *     If we move the higher column, we wouldn't get a larger area since the area 
 * is dominant by the shorter column. Only moving the shorter column may get a larger
 * area
 * 
**/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            maxArea = max(maxArea, (right - left) * min(height[left], height[right]));
            if (height[right] > height[left]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};

/**
 * Tests:
 * 1. empty array
 * 2. array with 1 element
 * 3. array with 2 element
 * 4. the left column is heigher
 * 5. the right column is heigher
[]
[1]
[1,2]
[4,5,2,3,8]
[4,8,2,3,5]
**/