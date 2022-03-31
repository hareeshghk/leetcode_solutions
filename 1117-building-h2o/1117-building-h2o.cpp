class H2O {
    int hcount, ocount;
    condition_variable cv;
    mutex m;
public:
    H2O() {
        hcount = 2;
        ocount = 1;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [this](){return hcount > 0 ;});
        --hcount;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        if (hcount == 0 && ocount == 0) {
            hcount = 2;
            ocount = 1;
            cv.notify_all();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [this](){return ocount >0;});
        --ocount;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        if (hcount == 0 && ocount == 0) {
            hcount = 2;
            ocount = 1;
            cv.notify_all();
        }
    }
};