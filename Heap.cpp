
// Max Heap, base type is integer, max size is 100
class MaxHeap {
    int max_size;
    int size;
    vector<int> heap;
public:
    MaxHeap() : max_size(100) {
        heap.resize(100);
        size = 0;
    }

    MaxHeap(vector<int>& data) {
        heap = data;
        max_size = heap.size();
        size = heap.size();
        
        for (int i = size/2; i >= 0; i--) {
            bubble_down(i);
        }
    }

    ~MaxHeap() {
        heap.clear();
    }

    bool insert(int val) {
        if (size >= max_size) return false;
        heap[size] = val;
        size++;

        // bubble up
        int current = size-1;
        while (current > 0) {
            int parent = (current-1)/2;
            if (heap[parent] < heap[current]) {
                swap(heap[current], heap[parent]);
                current = parent;
            } else break;
        }
        return true;
    }

    bool pop() {
        if (size == 0) return false;
        swap(heap[0], heap[size-1]);
        size--;

        bubble_down(0);

        return true;
    }

    void bubble_down(int inx) {
        int current = inx;
        while (current < size) {
            int next_l = current * 2 + 1;
            int next_r = current * 2 + 2;
            if (next_l >= size) break; // current is a leaf
            else { // current has at least one child
                int tmp_cur = current;
                if (next_r >= size) {
                    if (heap[next_l] > heap[current]) {
                        swap(heap[next_l],heap[current]);
                        current = next_l;
                    }
                } else {
                    if (heap[next_l] > heap[current] && 
                        heap[next_l] >= heap[next_r]) { // left child is the max
                        swap(heap[next_l],heap[current]);
                        current = next_l;
                    }
                    else if (heap[next_r] > heap[current] && 
                        heap[next_r] > heap[next_l]) { // right child is the max
                        swap(heap[next_r],heap[current]);
                        current = next_r;
                    }
                }
                
                if (tmp_cur == current) break; // no update
            }
        }
    }

    int top() {
        if (size == 0) return -1;
        return heap[0];
    }

    bool empty() {
        return size == 0;
    }

    int get_size() { return size; }
    
    void print() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " "; 
        }
        cout << endl;
    }
};

int main() {
    
    vector<int> test = {1,4,2,6,8,6,2,7,323,645,2,3,6,895,12};
    MaxHeap pq = MaxHeap(test);
    pq.print();
    // for (int i : test) {
    //     pq.insert(i);
    //     cout << pq.top() << endl;
    // }
    
    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
}