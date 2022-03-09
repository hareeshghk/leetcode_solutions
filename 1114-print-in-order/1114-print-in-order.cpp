class Foo {
    mutex firstlock, secondlock;
public:
    Foo() {
        firstlock.lock();
        secondlock.lock();
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstlock.unlock();
    }

    void second(function<void()> printSecond) {
        firstlock.lock();
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        firstlock.unlock();
        secondlock.unlock();
    }

    void third(function<void()> printThird) {
        secondlock.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        secondlock.unlock();
    }
};