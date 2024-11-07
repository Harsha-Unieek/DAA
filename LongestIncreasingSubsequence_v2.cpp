// This is an improvement of v1, done with DYNAMIC PROGRAMMING
// Time Complexity O(n^2)

#include <bits/stdc++.h>
using namespace std;

int incSubseq(vector<int>& arr, int cur, int prev, vector<vector<int>>& dp) {
    if (cur == arr.size()) return 0;
    if (dp[cur][prev + 1] != -1) return dp[cur][prev + 1];
    
    int notinc = incSubseq(arr, cur + 1, prev, dp);
    int inc = 0;
    if (prev == -1 || arr[cur] > arr[prev]) {
        inc = 1 + incSubseq(arr, cur + 1, cur, dp);
    }
    
    return dp[cur][prev + 1] = max(inc, notinc);
}

int main() {
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18, 1, 19};
    int n = arr.size();
    
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    
    cout << incSubseq(arr, 0, -1, dp);
    return 0;
}
