class FizzBuzz {
private:
    int n;
    condition_variable cv;
    mutex m;
    int current_number;
public:
    FizzBuzz(int n) {
        this->n = n;
        current_number = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> ul(m);
            cv.wait(ul, [this](){return (current_number > n || (current_number%3==0 && current_number%5!=0));});
            if (current_number > n) return;
            printFizz();
            ++current_number;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> ul(m);
            cv.wait(ul, [this](){return (current_number > n || (current_number%3!=0 && current_number%5==0));});
            if (current_number > n) return;
            printBuzz();
            ++current_number;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> ul(m);
            cv.wait(ul, [this](){return (current_number > n || (current_number%3==0 && current_number%5==0));});
            if (current_number > n) return;
            printFizzBuzz();
            ++current_number;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> ul(m);
            cv.wait(ul, [this](){return (current_number > n || (current_number%3!=0 && current_number%5!=0));});
            if (current_number > n) return;
            printNumber(current_number);
            ++current_number;
            cv.notify_all();
        }
    }
    
    // void CallNext(int num) {
    //     if(num%3!=0 && num%5 !=0) {
    //         cv4.notify_one();
    //         return;
    //     }
    //     if (num%3!=0 && num%5 ==0) {
    //         cv2.notify_one();
    //         return;
    //     }
    //     if (num%3==0 && num%5 !=0) {
    //         cv1.notify_one();
    //         return;
    //     }
    //     if (num%3==0 && num%5 ==0) {
    //         cv3.notify_one();
    //         return;
    //     }
    // }
};