#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
    unordered_set<string> visited;
    vector<string> result;
    mutex m;
    condition_variable cv;
    string hostname;
    queue<string> pending_jobs;
    vector<thread> worker_threads;
    int running_workers; bool done;
    string extracthostname(string url) {
        int start = url.find('/')+2;
        int end = url.find('/', start);
        if (end == string::npos) return url.substr(start);
        return url.substr(start, end-start);
    }
    
    void worker_func(HtmlParser &htmlParser) {
        while (true) {
            unique_lock<mutex> ul(m);
            cv.wait(ul, [this](){return (pending_jobs.size() != 0 || done);});
            if (done) return;
            auto url = pending_jobs.front();
            pending_jobs.pop();
            result.push_back(url);
            ++running_workers;
            ul.unlock();
            auto neighbours = htmlParser.getUrls(url);
            ul.lock();
            for (auto neighbour : neighbours) {
                if (!matched(neighbour)) continue;
                if (visited.find(neighbour) == visited.end()) {
                    visited.insert(neighbour);
                    pending_jobs.push(neighbour);
                }
            }
            --running_workers;
            if (running_workers == 0 && pending_jobs.empty()) {
                done = true;
            }
            cv.notify_all();
        }
    }
    
    bool matched(string &neighbour) {
        return hostname==extracthostname(neighbour);
    }
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        hostname = extracthostname(startUrl);
        visited.insert(startUrl);
        // adding current url to queue so it can add neighbours
        pending_jobs.push(startUrl);
        running_workers = 0;
        done = false;
        int num_threads = thread::hardware_concurrency();
        worker_threads.resize(num_threads);
        for (int i  = 0; i < num_threads; ++i) {
            worker_threads[i] = thread(&Solution::worker_func, this, ref(htmlParser));
        }
        for (int i  = 0; i < num_threads; ++i) {
            worker_threads[i].join();
        }
        return result;
    }
};
