

class Solution {
public:
	// Sort, Time complexity: O(nlogn), Space complexity: O(1)
    int missingNumber_sort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) return i;
        }
        
        return nums.size();
    }

    // hash set, Time complexity: O(n), Space complexity: O(n)
    int missingNumber_hashset(vector<int>& nums) {
        unordered_set<int> tset;
        for (int i : nums) {
            tset.insert(i);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (tset.find(i) == tset.end()) return i;
        }
        
        return nums.size();
    }
};