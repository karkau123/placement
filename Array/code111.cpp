
#include <bits/stdc++.h>
using namespace std;
int solve(int N, vector<int> A) {
    int maxA = *max_element(A.begin(), A.end());
    vector<int> B;  
    for (int p = 1; p <= maxA; ++p) {
        bool has_multiple = false;
        for (int a : A) {
            if (a % p == 0) {
                has_multiple = true;
                break;
            }
        }
        if (has_multiple) {
            B.push_back(p); 
        }
    }
    int largest_special = -1;
    for (int p : B) {
        int count = 0;
        for (int a : A) {
            if (a % p == 0) {
                count++;
            }
        }
        if (count == p) {
            largest_special = max(largest_special, p);
        }
    }

    return largest_special;
}

int main() {
    int N;
    cin >> N;  // Read the size of array A
    vector<int> A(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];  // Read array A elements
    }

    int result = solve(N, A);
    cout << result << endl;  // Output the largest special number
    return 0;
}
