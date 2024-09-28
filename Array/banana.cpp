#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), h(n), maxReach(n);

    // Input positions and heights of the bananas
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    // Initialize maxReach as each banana can reach at least its own position
    for (int i = 0; i < n; i++) {
        maxReach[i] = a[i];
    }

    // Process from right to left to handle rightward toppling
    for (int i = n - 1; i >= 0; i--) {
        maxReach[i] = max(maxReach[i], a[i] + h[i]);  // Max reach to the right
        // If this banana can topple the next one
        if (i < n - 1 && maxReach[i] >= a[i + 1]) {
            maxReach[i] = max(maxReach[i], maxReach[i + 1]);  // Extend the reach
        }
    }

    // Process from left to right to handle leftward toppling
    for (int i = 0; i < n; i++) {
        maxReach[i] = max(maxReach[i], a[i] - h[i]);  // Max reach to the left
        // If this banana can topple the previous one
        if (i > 0 && maxReach[i - 1] >= a[i]) {
            maxReach[i] = max(maxReach[i], maxReach[i - 1]);
        }
    }

    // Output the maximum coordinate each banana reaches
    for (int i = 0; i < n; i++) {
        cout << "Banana at position " << a[i] << " reaches " << maxReach[i] << endl;
    }

    return 0;
}
