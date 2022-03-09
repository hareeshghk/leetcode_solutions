#include <semaphore.h>
class ZeroEvenOdd {
private:
    int n;
    sem_t zdone, odone, edone;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&zdone, 0, 1);
        sem_init(&odone, 0, 0);
        sem_init(&edone, 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i =1; i <= n;i++) {
            sem_wait(&zdone);
            printNumber(0);
            if (i&1) {
                sem_post(&odone);
            } else {
                sem_post(&edone);
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i+=2) {
            sem_wait(&edone);
            printNumber(i);
            sem_post(&zdone);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i+=2) {
            sem_wait(&odone);
            printNumber(i);
            sem_post(&zdone);
        }
    }
};