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

// Time conplexity: O(MlogM)

#include <queue>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int time = -1;
        // Dijkstra
        vector<bool> visited(N+1, false);
        vector<int> weight(N+1, INT_MAX);

        weight[K] = 0;
        while (true) {
            vector<int> node = {-1, INT_MAX};
            for (int i = 1; i <= N; i++) {
                if (!visited[i]) {
                    if (weight[i] < node[1]) {
                        node[0] = i;
                        node[1] = weight[i];
                    }
                }
            }
            if (node[0] == -1) break;

            visited[node[0]] = true;
            time = max(time, node[1]);
            for (auto& tuple : times) {
                if (tuple[0] == node[0] && !visited[tuple[1]]) {
                    weight[tuple[1]] = min(weight[tuple[1]], node[1] + tuple[2]);
                }
            }
        }
        
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) return -1;
        }

        return time;
    }
};