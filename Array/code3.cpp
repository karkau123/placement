#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        // Read teacher positions
        vector<int> teachers(m);
        for (int i = 0; i < m; i++) {
            cin >> teachers[i];
        }

        // Sort teacher positions to allow binary search
        sort(teachers.begin(), teachers.end());

        // Process each query
        while (q--) {
            int pos;
            cin >> pos;

            int result = 0;

            // If David's position is to the left of the leftmost teacher
            if (pos < teachers[0]) {
                result = teachers[0] - pos;
            }
            // If David's position is to the right of the rightmost teacher
            else if (pos > teachers.back()) {
                result = pos - teachers.back();
            }
            // Otherwise, find the nearest teacher using binary search
            else {
                auto it = upper_bound(teachers.begin(), teachers.end(), pos);

                int closest_right = (it != teachers.end()) ? abs(*it - pos) : 1e9;
                int closest_left = (it != teachers.begin()) ? abs(*(it - 1) - pos) : 1e9;

                result = min(closest_left, closest_right);
            }

            cout << result << "\n";
        }
    }

    return 0;
}
