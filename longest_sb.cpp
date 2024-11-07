#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n) {
    // Create a DP array to store the length of LIS ending at each index
    vector<int> dp(n, 1);  // Initially, each element is a subsequence of length 1

    // Build the DP table
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // The length of the longest increasing subsequence will be the max value in dp
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The length of the longest increasing subsequence is " << longestIncreasingSubsequence(arr, n) << endl;

    return 0;
}
