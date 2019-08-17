int choose_pivot1(vector<int>& nums, int l, int r) { // return the index 0
    return l;
}

int partition(vector<int>& nums, int p, int l, int r) {
    swap(nums[l], nums[p]);
    int l_iter = l+1;
    int r_iter = r;
    while (true) {
        while (l_iter <= r && nums[l_iter] <= nums[l]) {
            l_iter++;
        }
        while (r >= l + 1 && nums[r_iter] > nums[l]) {
            r_iter--;
        }
        if (r_iter < l_iter) break;
        swap(nums[l_iter], nums[r_iter]);
    }

    swap(nums[l], nums[r_iter]);
    return r_iter;
}

int quick_select(vector<int>& nums, int k, int l, int r) {
    if (nums.size() <= k) return INT_MIN;
    int pivot = choose_pivot1(nums, l, r);
    int p_inx = partition(nums, pivot, l, r);
    if (p_inx == k) return nums[p_inx];
    else if (p_inx < k){
        return quick_select(nums, k, p_inx + 1, r);
    } else {
        return quick_select(nums, k, l, p_inx - 1);
    }
    return 0;
}

void quick_sort(vector<int>& nums, int l, int r) {
    if(l >= r) return;
    int pivot = choose_pivot1(nums, l, r);
    int p_inx = partition(nums, pivot, l, r);
    quick_sort(nums, p_inx+1, r);
    quick_sort(nums, l, p_inx-1);
}

int main() {
    std::cout << "Hello World!\n";
    vector<int> test = {1,2,52,4,76,7,3,5,7,8};
    // int res = quick_select(test,5-1,0, test.size()-1);
    quick_sort(test, 0, test.size()-1);
    for (int i : test) {
        cout << i << " ";
    }
    cout << "\n";
    // cout << res << endl;
    return 0;
}