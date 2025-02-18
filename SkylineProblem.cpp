#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    // Create a list of events
    vector<pair<int, int>> events; // (x, height)
    for (const auto& building : buildings) {
        events.emplace_back(building[0], -building[2]); // Start of a building
        events.emplace_back(building[1], building[2]);  // End of a building
    }

    // Sort events
    sort(events.begin(), events.end());

    // Resultant skyline points
    vector<vector<int>> result;
    // Max-heap to keep track of heights
    priority_queue<pair<int, int>> maxHeap; // (height, end)
    maxHeap.emplace(0, INT_MAX); // Initialize with ground level

    // Previous maximum height
    int prevMaxHeight = 0;

    for (const auto& event : events) {
        int x = event.first;
        int h = event.second;

        if (h < 0) { // Start of a building
            maxHeap.emplace(h, x); // Use negative height for max-heap
        } else { // End of a building
            // Remove the height from the heap
            // We can't directly remove from a priority queue, so we use a lazy removal approach
            while (!maxHeap.empty() && maxHeap.top().second <= x) {
                maxHeap.pop();
            }
        }

        // Get the current maximum height
        int currentMaxHeight = -maxHeap.top().first;

        // If the maximum height changes, add a key point
        if (currentMaxHeight != prevMaxHeight) {
            result.push_back({x, currentMaxHeight});
            prevMaxHeight = currentMaxHeight;
        }
    }

    return result;
}

// Example usage
int main() {
    vector<vector<int>> buildings1 = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> skyline1 = getSkyline(buildings1);
    
    cout << "Skyline 1: ";
    for (const auto& point : skyline1) {
        cout << "[" << point[0] << "," << point[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> buildings2 = {{0,2,3},{2,5,3}};
    vector<vector<int>> skyline2 = getSkyline(buildings2);
    
    cout << "Skyline 2: ";
    for (const auto& point : skyline2) {
        cout << "[" << point[0] << "," << point[1] << "] ";
    }
    cout << endl;

    return 0;
}
