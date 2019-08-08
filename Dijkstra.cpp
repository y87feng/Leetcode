#include <queue>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int time = -1;
        // Dijkstra
        vector<bool> visited(N+1, false);
        auto comp = [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        pq.push({K,0});
        while (!pq.empty()) {
            while (visited[pq.top()[0]]) {
                pq.pop();
                if (pq.empty()) break;
            }
            if (pq.empty()) break;
            
            vector<int> node = pq.top();
            pq.pop();
            visited[node[0]] = true;
            time = max(time, node[1]);
            for (auto& tuple : times) {
                if (tuple[0] == node[0] && !visited[tuple[1]]) {
                    pq.push({tuple[1], node[1] + tuple[2]});
                }
            }
        }
        
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) return -1;
        }

        return time;
    }
};