class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
        int m = nums1.size();
        int n = nums2.size();
        
        if (m + n == 1) return m == 0 ? nums2[0] : nums1[0];
        
        int low = -1; // nums1 might be empty
        int hi = m - 1;
        
        while (low <= hi) {
            int i = (low+hi) / 2; 
            
            int j = (n+m)/2 - 2 - i;
            
            if (j >= n) { // check if j is in the range 
                low = i + 1;
                continue;
            } else if (j < -1) {
                hi = i-1;
                continue;
            }
            
            // A[i] <= B[j+1] && B[j] <= A[i+1]
            if ((i < 0 || j+1>= n || nums1[i] <= nums2[j+1]) &&
               (j < 0 || i + 1 >= m || nums2[j] <= nums1[i+1])) { 
                if ((m+n)%2 == 1) // odd 
                {
                    return min(i + 1 < m ? nums1[i+1] : INT_MAX, 
                              j + 1 < n ? nums2[j+1] : INT_MAX);
                }
                else {
                    double first = min(i + 1 < m ? nums1[i+1] : INT_MAX, 
                              j + 1 < n ? nums2[j+1] : INT_MAX);
                    double second = max(i >= 0 ? nums1[i] : INT_MIN, 
                              j >= 0 ? nums2[j] : INT_MIN);
                    return (first + second) / 2;
                }
            }

            // A[i] <= B[j+1] && B[j] > A[i+1], i is too small
            if ((i < 0 || j+1>= n || nums1[i] <= nums2[j+1]) &&
               !(j < 0 || i + 1 >= m || nums2[j] <= nums1[i+1])){
                low = i + 1;
            } else {  // A[i] > B[j+1] && B[j] <= A[i+1], i is too large
                hi = i - 1;
            }
        }
        
        return 0;
    }
};