class FizzBuzz {
private:
    int n;
    int curnumber;
    mutex m;
    condition_variable cv1,cv2,cv3,cv4;
public:
    FizzBuzz(int n) {
        this->n = n;
        curnumber = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (curnumber <= n) {
            unique_lock<mutex> ul(m);
            cv4.wait(ul, [this](){return ((curnumber%3==0 && curnumber%5 != 0) || curnumber > n);});
            if (curnumber > n) break;
            printFizz();
            ++curnumber;
            if (curnumber > n) {
                // cout << curnumber << endl;
                Notifyall();
                break;
            }
            FreeaCV();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (curnumber <= n) {
            unique_lock<mutex> ul(m);
            cv3.wait(ul, [this](){return ((curnumber%3!=0 && curnumber%5 == 0) || curnumber > n);});
            if (curnumber > n) break;
            printBuzz();
            ++curnumber;
            if (curnumber > n) {
                // cout << curnumber << endl;
                Notifyall();
                break;
            }
            FreeaCV();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (curnumber <= n) {
            unique_lock<mutex> ul(m);
            cv2.wait(ul, [this](){return ((curnumber%3==0 && curnumber%5 == 0) || curnumber > n);});
            if (curnumber > n) break;
            printFizzBuzz();
            ++curnumber;
            if (curnumber > n) {
                // cout << curnumber << endl;
                Notifyall();
                break;
            }
            FreeaCV();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (curnumber <= n) {
            unique_lock<mutex> ul(m);
            cv1.wait(ul, [this](){return ((curnumber%3!=0 && curnumber%5 != 0) || curnumber > n);});
            if (curnumber > n) break;
            printNumber(curnumber);
            ++curnumber;
            if (curnumber > n) {
                // cout << curnumber << endl;
                Notifyall();
                break;
            }
            FreeaCV();
        }
    }
    
    void Notifyall() {
        cv1.notify_all();
        cv2.notify_all();
        cv3.notify_all();
        cv4.notify_all();
    }
    
    inline void FreeaCV() {
        if (curnumber%3==0 && curnumber%5 == 0) {
            cv2.notify_one();
        } else if (curnumber%3==0 && curnumber%5 != 0) {
            cv4.notify_one();
        } else if (curnumber%3!=0 && curnumber%5 == 0) {
            cv3.notify_one();
        } else {
            cv1.notify_one();
        }
    }
};