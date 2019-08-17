vector<int> merge_sort(vector<int>& nums, int l, int r) {
    if (l > r) return {};
    if (l == r) return {nums[l]};
    int mid = (l+r) / 2;
    vector<int> left = merge_sort(nums, l, mid);
    vector<int> right = merge_sort(nums, mid + 1, r);

    // merge

    int iter_l = 0;
    int iter_r = 0;
    vector<int> res(r-l+1);
    for (int i = 0; i < res.size(); i++) {
        if (iter_l < left.size() && iter_r < right.size()) {
            if (left[iter_l] < right[iter_r]) {
                res[i] = left[iter_l];
                iter_l++;
            } else {
                res[i] = right[iter_r];
                iter_r++;
            }
        } else if (iter_l < left.size()) { // only left array have items left
            res[i] = left[iter_l];
            iter_l++;
        } else { // only right array have items left
            res[i] = right[iter_r];
            iter_r++;
        }
    }
    return res;
 }