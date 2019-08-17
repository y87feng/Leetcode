#include <queue>
#include <vector>
#include <stack>
using namespace std;

// Heap data structure
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto Distance = [](vector<int> a) {
            return a[0] * a[0] + a[1] * a[1];
        };
        auto Compare = [](vector<int>& a, vector<int>& b) { 
            return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
         }; 
        priority_queue<vector<int>, vector<vector<int>>, decltype(Compare)> p(Compare);

        
        for (auto& pair : points) {
            p.push(pair);
        }
        
        vector<vector<int>> res;
        for (int i = 0; i < K; i++) {
            res.push_back(p.top());
            p.pop();
        }

        return res;

    }
};

// Sort
class Solution1 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto Compare = [](vector<int>& a, vector<int>& b) { 
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        }; 
        
        sort(points.begin(), points.end(), Compare);

        vector<vector<int>> res;
        for (int i = 0; i < K; i++) {
            res.push_back(points[i]);
        }

        return res;
    }
};

// Heapify
class Solution2 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto Compare = [](vector<int>& a, vector<int>& b) { 
            return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
        }; 
        
        make_heap(points.begin(), points.end(), Compare);

        vector<vector<int>> res;
        for (int i = 0; i < K; i++) {
            res.push_back(v.front());
            pop_heap(v.begin(), v.end()); v.pop_back();
        }

        return res;
    }
};


// Divide & Conquer

#include <stdlib.h>
#include <time.h>
class Solution3 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        srand (time(NULL));
        sort()
    }

    void sort(vector<vector<int>>& points, int l, int r, int K) {
        if (l > r) return;
        
        int k = rand() % (r-l + 1) + l;
        swap(points[i], points【k);
        
    }
};