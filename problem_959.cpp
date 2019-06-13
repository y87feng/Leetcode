class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        if (grid.size() == 0) return 0;
        if (grid[0].size() == 0) return 0;
        // expand the height and width to 3 times of them

        int height = grid.size();
        int width = grid[0].size();
        vector<vector<bool>> newgrid(3*height, vector<bool>(3*width, true));
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == '/') {
                    newgrid[3*i][3*j+2] = false;
                    newgrid[3*i+1][3*j + 1] = false;
                    newgrid[3*i+2][3*j] = false;
                }
                if (grid[i][j] == '\\') {
                    newgrid[3*i][3*j] = false;
                    newgrid[3*i+1][3*j+1] = false;
                    newgrid[3*i+2][3*j+2] = false;
                }
            }
        }

        int res = 0;

        for (int i = 0; i < 3 * height; i++) {
            for (int j = 0; j < 3 * width; j++) {
                if (newgrid[i][j]) {
                    res++;
                    DFS(newgrid, i , j);
                }
            }
        }
        return res;
    }

    void DFS(vector<vector<bool>>& newgrid, int x, int y) {
        if (x >= 0 && x < newgrid.size() && y >= 0 && y < newgrid[0].size()
        && newgrid[x][y]) {
            newgrid[x][y] = false;
            DFS(newgrid, x - 1, y);
            DFS(newgrid, x + 1, y);
            DFS(newgrid, x, y - 1);
            DFS(newgrid, x, y + 1);
        }
    }
};


class UnionFind {
    vector<int> parent;
    int blocks;

public:
    UnionFind(int size) {
        parent.resize(size, -1);
        blocks = 0;
    }

    int Find(int pos) {
        if (parent[pos] == -1 || parent[pos] == pos) return parent[pos];
        parent[pos] = Find(parent[pos]); // compress
        return parent[pos];
    }

    int GetBlocks() {return blocks;}

    void Union(int pos1, int pos2) { // positions are valid
        int p1 = Find(pos1);
        int p2 = Find(pos2);
        if (p1 == p2) return; // both empty or have same parent
        if (p1 == -1 || p2 == -1) return; // one is empty
        parent[p2] = p1;
        blocks--;
    }
    
    void Insert(int pos) {
        if (parent[pos] != -1) return;
        blocks++;
        parent[pos] = pos;
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        if (grid.size() == 0) return 0;
        if (grid[0].size() == 0) return 0;
        // expand the height and width to 3 times of them

        int height = grid.size();
        int width = grid[0].size();
        UnionFind uf{3*height * 3*width};
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        if (grid[i][j] == '/' && x == 2 - y) continue;
                        if (grid[i][j] == '\\' && x == y) continue;
                        uf.Insert((3*i+x) * (3 * width) + 3*j+y);
                        if (3*j+y > 0) uf.Union((3*i+x) * (3 * width) + 3*j+y - 1, (3*i+x) * (3 * width) + 3*j+y);
                        if (3*i+x > 0) uf.Union((3*i+x-1) * (3 * width) + 3*j+y, (3*i+x) * (3 * width) + 3*j+y);
                    }
                }
            }
        }
        
        return uf.GetBlocks();
    }
};