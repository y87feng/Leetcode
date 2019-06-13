class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        if (grid[0].size() == 0) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols,0));
        
        dp[0][0] = grid[0][0];
        // init first column
        for (int i = 1; i < rows; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        // init first row
        for (int j = 1; j < cols; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[rows-1][cols-1];
    }
};


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        if (grid[0].size() == 0) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(2, vector<int>(cols,0));
        
        dp[0][0] = grid[0][0];
        // init first row
        for (int i = 1; i < rows; i++) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        
        
        for (int i = 1; i < rows; i++) {
            dp[1][0] = dp[0][0] + grid[i][0];
            for (int j = 1; j < cols; j++) {
                dp[1][j] = min(dp[0][j], dp[1][j-1]) + grid[i][j];
            }
            
            for (int j = 0; j < cols; j++) {
                dp[0][j] = dp[1][j];
                dp[1][j] = 0;
            }
        }
        
        return dp[0][cols-1];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        if (grid[0].size() == 0) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        int minSum = INT_MAX;
        DFS(0,0,0,minSum,grid);
        return minSum;
    }
    
    void DFS(int x, int y, int Sum, int& minSum, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        Sum += grid[x][y];
        if (x == rows-1 && y == cols-1) {
            minSum = min(minSum, Sum);
            return;
        }
        if (x+1 < rows) {
            DFS(x+1,y,Sum,minSum,grid);
        }
        if (y+1 < cols) {
            DFS(x,y+1,Sum,minSum,grid);
        }
    }
};


class Solution {
    struct Info {
        int x;
        int y;
        int sum;
        Info(int i, int j, int s) : x(i),y(j),sum(s) {}
        Info() : x(0), y(0), sum(0) {}
    };
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        if (grid[0].size() == 0) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        int minSum = INT_MAX;
        queue<Info> bfs_q;
        
        Info first_p(0,0, grid[0][0]);

        bfs_q.push(first_p);

        while (!bfs_q.empty()) {
            Info info = bfs_q.front();
            bfs_q.pop();
            if (info.x == rows-1 && info.y == cols-1) {
                minSum = min(minSum, info.sum);
            }

            if (info.x+1 < rows) {
                Info new_info(info.x+1, info.y, info.sum+grid[info.x+1][info.y]);
                bfs_q.push(new_info);
            }

            if (info.y+1 < cols) {
                Info new_info(info.x, info.y+1, info.sum+grid[info.x][info.y+1]);
                bfs_q.push(new_info);
            } 
        }
        return minSum;
    }
};