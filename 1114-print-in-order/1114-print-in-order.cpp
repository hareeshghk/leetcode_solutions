class Foo {
    bool firstdone, seconddone;
    mutex mtx;
    condition_variable cv;
public:
    Foo() {
        firstdone = false;
        seconddone = false;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstdone = true;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> ul(mtx);
        cv.wait(ul, [this](){return firstdone;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        seconddone = true;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> ul(mtx);
        cv.wait(ul, [this](){return seconddone;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};