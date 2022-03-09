#include <semaphore.h>
class FooBar {
private:
    int n;
    sem_t foodone, bardone;

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&foodone, 0, 0);
        sem_init(&bardone, 0, 0);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            sem_post(&foodone);
            sem_wait(&bardone);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&foodone);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            sem_post(&bardone);
        }
    }
};