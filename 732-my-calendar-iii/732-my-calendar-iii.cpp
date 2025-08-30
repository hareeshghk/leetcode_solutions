#include <algorithm>
#include <map>
using namespace std;

class MyCalendarThree {
    map<int, int> bookings;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        bookings[start]++;
        bookings[end]--;
        int currentbookings  = 0;
        int maxbooking = 0;
        for (auto booking : bookings) {
            currentbookings += booking.second;
            maxbooking = max(maxbooking, currentbookings);
        }
        return maxbooking;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
