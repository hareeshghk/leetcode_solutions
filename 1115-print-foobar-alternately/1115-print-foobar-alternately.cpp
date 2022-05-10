
class FooBar {
private:
    int n;
    bool footurn;
    mutex mtx;
    condition_variable cv;
public:
    FooBar(int n) {
        this->n = n;
        footurn = true;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> ul(mtx);
            cv.wait(ul, [this]{return footurn;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            footurn = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> ul(mtx);
            cv.wait(ul, [this]{return !footurn;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            footurn = true;
            cv.notify_one();
        }
    }
};