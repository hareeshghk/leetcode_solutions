class FizzBuzz {
private:
    int n;
    condition_variable cv1,cv2,cv3,cv4;
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
            cv1.wait(ul, [this](){return (current_number > n || (current_number%3==0 && current_number%5!=0));});
            if (current_number > n) return;
            printFizz();
            ++current_number;
            CallNext(current_number);
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> ul(m);
            cv2.wait(ul, [this](){return (current_number > n || (current_number%3!=0 && current_number%5==0));});
            if (current_number > n) return;
            printBuzz();
            ++current_number;
            CallNext(current_number);
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> ul(m);
            cv3.wait(ul, [this](){return (current_number > n || (current_number%3==0 && current_number%5==0));});
            if (current_number > n) return;
            printFizzBuzz();
            ++current_number;
            CallNext(current_number);
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> ul(m);
            cv4.wait(ul, [this](){return (current_number > n || (current_number%3!=0 && current_number%5!=0));});
            if (current_number > n) return;
            printNumber(current_number);
            ++current_number;
            CallNext(current_number);
        }
    }
    
    void CallNext(int num) {
        if (num > n) {
            cv1.notify_all();cv2.notify_all();cv3.notify_all();cv4.notify_all();
            return;
        }
        
        if(num%3!=0 && num%5 !=0) {
            cv4.notify_one();
            return;
        }
        if (num%3!=0 && num%5 ==0) {
            cv2.notify_one();
            return;
        }
        if (num%3==0 && num%5 !=0) {
            cv1.notify_one();
            return;
        }
        if (num%3==0 && num%5 ==0) {
            cv3.notify_one();
            return;
        }
    }
};