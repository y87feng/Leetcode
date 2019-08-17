int choose_pivot(vector<int>& nums, int l, int r) {
    return l;
}

int partition(vector<int>& nums, int p, int l, int r) {
    swap(nums[p], nums[l]);
    // now nums[l] is the pivot
    int iter_l = l+1;
    int iter_r = r;
    while (true) {
        while (iter_l <= r && nums[iter_l] <= nums[l]) {
            iter_l++;
        }
        while (iter_r > l && nums[iter_r] > nums[l]) {
            iter_r--;
        }
        if (iter_r < iter_l) break;
        swap(nums[iter_l], nums[iter_r]);
    }
    
    swap(nums[iter_r], nums[l]);
    return iter_r;
}

int quick_select(vector<int>& nums, int k, int l, int r) {
    if (nums.size() <= k) return INT_MIN;
    int p = choose_pivot(nums, l, r);
    int inx = partition(nums, p, l, r);
    
    if (inx == k) return nums[inx];
    else if (inx > k) {
        return quick_select(nums, k, l, inx-1);
    } else {
        return quick_select(nums, k, inx+1, r);
    }
}

class KthLargest {
    int k_th;
    priority_queue<int, vector<int>, greater<int>> largest_k;
public:
    KthLargest(int k, vector<int>& nums) {
        k_th = k;
        quick_select(nums, nums.size()-k, 0, nums.size()-1);
        
        for (int i = max(0, (int)nums.size()-k); i < nums.size(); i++) {
            largest_k.push(nums[i]);
            cout << nums[i];
        }
    }
    
    int add(int val) {
        if (largest_k.empty() || largest_k.size() < k_th) largest_k.push(val);
        else if (val > largest_k.top()) {
            largest_k.pop();
            largest_k.push(val);
        }
        return largest_k.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */