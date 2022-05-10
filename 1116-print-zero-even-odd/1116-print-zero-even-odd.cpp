class ZeroEvenOdd {
private:
    int n;
    mutex mt;
    int turn; // 0 for 0, -1 for odd, 1 for even
    condition_variable cv;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        turn = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; ++i) {
            unique_lock<mutex> ul(mt);
            cv.wait(ul, [this]{return turn==0;});
            printNumber(0);
            if (i%2 == 1) {
                turn = -1;
            } else {
                turn = 1;
            }
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i+=2) {
            unique_lock<mutex> ul(mt);
            cv.wait(ul, [this]{return turn==1;});
            printNumber(i);
            turn = 0;
            cv.notify_all();
        }
        
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i+=2) {
            unique_lock<mutex> ul(mt);
            cv.wait(ul, [this]{return turn==-1;});
            printNumber(i);
            turn = 0;
            cv.notify_all();
        }
    }
};