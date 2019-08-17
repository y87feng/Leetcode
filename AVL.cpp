class AVL {
    vector<vector<int>> tree; // [key, value, height]
    int size;

    AVL() {
        tree.resize(1000, {});
        size = 0;
    }

public:
    int get_size() { return size; }
    bool empty() { return size == 0; }
    void insert(int k, int v) {
        int iter = 0;
        while (tree[iter].size() != 0) {
            if (k == tree[iter][0]) {
                tree[iter][1] = value;
                return;
            }
            if (k < tree[iter][0]) iter = 2*iter + 1;
            else iter = 2 * iter + 2;
        }

        tree[iter] = {k, v, 1};

        // update height
        while (iter > 0) {
            int parent = (iter-1) / 2;
            int l_c = parent * 2 + 1;
            int l_r = parent * 2 + 2;
            int left_h = tree[l_c].size() == 0 ? 0 : tree[l_c][2];
            int right_h = tree[l_r].size() == 0 ? 0 : tree[l_r][2];
            if (abs(left_h-right_h) == 2) {
                // fix
                break;
            } else {
                tree[parent][2] = max(left_h, right_h);
                iter = parent;
            }
        }
    }

    vector<int> search(int k) {
        int iter = 0;
        while (tree[iter].size() != 0) {
            if (tree[iter][0] == k) return tree[iter];
            else if (k < tree[iter][0]) {
                iter = 2*iter + 1;
            } else {
                iter = 2*iter + 2;
            }
        }

        // key doesn't exist
        return {};
    }

    void del(int k) {
        
    }
};