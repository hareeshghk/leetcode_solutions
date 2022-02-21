class node {
public:
    int start;
    int end;
    node *left, *right;
    node(int s, int e) {
        start = s;
        end = e;
        left = nullptr;
        right = nullptr;
    }
    bool insert(int start, int end) {
        if (end <= this->start) {
            if (this->left == nullptr) {
                this->left = new node(start, end);
                return true;
            }
            else return this->left->insert(start, end);
        } else if (start >= this->end) {
            if (this->right == nullptr) {
                this->right = new node(start, end);
                return true;
            }
            else return this->right->insert(start, end);
        }
        return false;
    }
};

class MyCalendar {
public:
    node *root;
    MyCalendar() {
        root = nullptr;
    }
    
    bool book(int start, int end) {
        if (root == nullptr) {
            root = new node(start, end);
            return true;
        }
        return root->insert(start, end);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */