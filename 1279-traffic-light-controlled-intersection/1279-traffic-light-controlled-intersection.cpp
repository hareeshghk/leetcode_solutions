class TrafficLight {
    // can be 1 or 2
    int green_acquired_road;
    mutex m;
    condition_variable cv;
    int roadA_cars_blocked, roadB_cars_blocked;
public:
    TrafficLight() {
        green_acquired_road = 1;
        roadA_cars_blocked = 0;
        roadB_cars_blocked = 0;
    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        unique_lock<mutex> ul(m);
        if (roadId == 1) {
            ++roadA_cars_blocked;
            if (green_acquired_road == 1) {
                crossCar();
            } else {
                cv.wait(ul, [this](){return (roadB_cars_blocked ==0);});
                turnGreen();
                green_acquired_road = 1;
                crossCar();
            }
            --roadA_cars_blocked;
            if (roadA_cars_blocked == 0) {
                cv.notify_all();
            }
        }
        else {
            ++roadB_cars_blocked;
            if (green_acquired_road == 2) {
                crossCar();
            } else {
                cv.wait(ul, [this](){return (roadA_cars_blocked ==0);});
                turnGreen();
                green_acquired_road = 2;
                crossCar();
            }
            --roadB_cars_blocked;
            if (roadB_cars_blocked == 0) {
                cv.notify_all();
            }
        }
    }
};