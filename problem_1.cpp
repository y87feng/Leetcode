class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> nums_set;
        for (int i = 0; i < nums.size(); i++) {
            if (nums_set.find(target-nums[i]) != nums_set.end()) return {nums_set[target-nums[i]], i};
            else {
                nums_set[nums[i]] = i;
            }
        }
        
        return {};
    }
};