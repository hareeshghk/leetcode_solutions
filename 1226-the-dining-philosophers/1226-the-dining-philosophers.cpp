class DiningPhilosophers {
    mutex m[5];
public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		unique_lock<mutex> ul1(m[philosopher], std::defer_lock), ul2(m[(philosopher+1)%5],std::defer_lock);
        lock(ul1,ul2);
        pickLeftFork();pickRightFork();eat();putLeftFork();putRightFork();
    }
};