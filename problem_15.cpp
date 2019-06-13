
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 2) return res; // edge case handle

        unordered_map<int,int> dup; // check duplicates 
        for (int num : nums) {
            dup[num]++;
        }


        return res;
    }
};

tests:
0,0,0
4,-2,-2
4, -1, -3

4，-2，4，-2

Thinking process:
Brute Force
Sort
HashTable

Should be careful of the duplicate tuples,
0 0 0
