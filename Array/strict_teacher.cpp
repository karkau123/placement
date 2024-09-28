#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void SolvePuzzle(int n, string str[]) {
    vector<int> nums;
    
    for (int i = 0; i < n; ++i) {
        string s = str[i];
        string num_str = "";
        
        for (char c : s) {
            if (isdigit(c)) {
                num_str += c;
            } else {
                if (!num_str.empty()) {
                    nums.push_back(stoi(num_str));
                    num_str = "";
                }
            }
        }
        
        if (!num_str.empty()) {
            nums.push_back(stoi(num_str));
        }
    }
    
    sort(nums.begin(), nums.end());
    
    for (int num : nums) {
        cout << num << endl;
    }
}

int main() {
    int n;
    cin >> n;
    string str[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    
    SolvePuzzle(n, str);
    
    return 0;
}
