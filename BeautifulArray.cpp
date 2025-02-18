code:-
#include <vector>
using namespace std;

vector<int> beautifulArray(int n) {
    vector<int> result;
    
    // Base case
    if (n == 1) {
        return {1};
    }
    
    // Recursive case
    vector<int> odds = beautifulArray((n + 1) / 2); // Generate beautiful array for odds
    vector<int> evens = beautifulArray(n / 2);      // Generate beautiful array for evens
    
    // Combine odds and evens
    for (int num : odds) {
        result.push_back(num * 2 - 1); // Convert to odd numbers
    }
    for (int num : evens) {
        result.push_back(num * 2);      // Convert to even numbers
    }
    
    return result;
}

// Example usage
#include <iostream>

int main() {
    int n = 5; // Change this value to test with different n
    vector<int> result = beautifulArray(n);
    
    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
