#include <set>
#include <string>
#include <utility>
using namespace std;

class SORTracker {
    set<pair<int, string>> sortedLocations;
    set<pair<int, string>>::iterator it = end(sortedLocations);
public:
    void add(string name, int score) {
        auto it1 = sortedLocations.insert({-score, name}).first;
        if (it == end(sortedLocations) || *it1 < *it) {
            --it;
        }
    }
    
    string get() {
        return (it++)->second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
