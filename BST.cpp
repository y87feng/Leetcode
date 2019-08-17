struct Node {
    int key;
    int value;
    Node* left;
    Node* right;

    Node(int k, int v) : key(k), value(v), left{nullptr}, right{nullptr} {}
};

class BST {
    Node* root;
    int size;
public:
    BST() : root(nullptr), size(0) {}

    int Get_size() {return size;}
    bool Empty() {return size == 0;}

    // if the key already exists, then update value
    void Insert(int k, int v) {
        if (root == nullptr) {
            Node * new_node = new Node(k,v);
            root = new_node;
            size++;
            return;
        }

        Node * iter = root;

        while (iter) {
            if (iter->key == k) {
                iter->value = v;
                break;
            }
            else if (k <= iter->key) {
                if (iter->left) iter = iter->left;
                else {
                    size++;
                    Node * new_node = new Node(k,v);
                    iter->left = new_node;
                }
            } else {
                if (iter->right) iter = iter->right;
                else {
                    size++;
                    Node * new_node = new Node(k,v);
                    iter->right = new_node;
                }
            }
        }
    }

    Node* Search(int k) {
        Node * iter = root;

        while (iter) {
            if (iter->key == k) return iter;
            else if (k <= iter->key) {
                iter = iter->left;
            } else {
                iter = iter->right;
            }
        }

        // the key doesn't exist
        return nullptr;
    }

    void Delete(int k) {
        Node* fake_head = new Node(0,0);
        fake_head->right = root;
        
        Node * parent = fake_head;
        Node * iter = root;
        
        // find the node and its parent
        while (iter) {
            if (iter->key == k) {
                size--;
                break;
            }
            else if (k <= iter->key) {
                parent = iter;
                iter = iter->left;
            } else {
                parent = iter;
                iter = iter->right;
            }
        }

        if (iter == nullptr) return;

        if (iter->right == nullptr && iter->left == nullptr) {
            if (parent->left == iter) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
            delete iter;
        } else if (iter->right == nullptr || iter->left == nullptr) {
            if (iter->left) {
                if (parent->left == iter) {
                    parent->left = iter->left;
                } else {
                    parent->right = iter->left;
                }
            } else {
                if (parent->left == iter) {
                    parent->left = iter->right;
                } else {
                    parent->right = iter->right;
                }
                delete iter;
            }
        } else {
            // find successor
            Node* suc = successor(iter);
            Node* pre_suc = presuccessor(iter);

            swap(suc->key, iter->key);
            swap(suc->value, iter->value);
            if (pre_suc == nullptr) iter->right = suc->right;
            else pre_suc->left = suc->right;
            delete suc;
        }

        root = fake_head->right;
        delete fake_head;
    }

    Node* successor(Node* node) {
        if (node->right == nullptr) return nullptr;
        Node* iter = node->right;
        while (iter->left) {
            iter = iter->left;
        }
        return iter;
    }

    Node* presuccessor(Node* node) {
        Node* iter = node->right;
        Node* parent = nullptr;
        while (iter->left) {
            parent = iter;
            iter = iter->left;
        }
        return parent;
    }
    
    void print_t() {
        print(root);
        cout << endl;
    }

    void print(Node* node) {
        if (!node) return;
        cout << node->key << " ";
        print(node->left);
        print(node->right);
    }
};

int main() {
    std::cout << "Hello World!\n";
    BST bst = BST();
    // test root
    bst.Insert(10,2);
    bst.print_t();
    // delete root
    bst.Delete(10);
    bst.print_t();
    
    // test insert
    bst.Insert(10,2);
    bst.Insert(5,2);
    bst.Insert(1,2);
    bst.Insert(12,2);
    bst.print_t();
    
    // test search
    auto test1 = bst.Search(5);
    cout << test1->key << " " << test1->value << endl;
    auto test2 = bst.Search(4);
    if (test2) cout << "error\n";
    
    // test delete (root)
    bst.Delete(10);
    bst.print_t();
    
    bst.Delete(5);
    bst.print_t();
    
    bst.Insert(10,1);
    bst.Insert(15,1);
    bst.Insert(13,2);
    bst.Insert(14,1);
    bst.print_t();
    bst.Delete(12);
    bst.print_t();
}