#include <bits/stdc++.h>
using namespace std;

void calculateAlignmentCost(vector<vector<int>>& dp, const string& str1, const string& str2) {
    int gap_penalty = 2; 

    vector<int> is_vowel(26, 0);
    string vowels = "aeiou";
    for (char ch : vowels) {
        is_vowel[ch - 'a'] = 1;
    }

    
    vector<vector<int>> mismatch_cost(26, vector<int>(26, 0));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i == j) 
                mismatch_cost[i][j] = 0; 
            else if (is_vowel[i] == is_vowel[j]) 
                mismatch_cost[i][j] = 1; 
            else 
                mismatch_cost[i][j] = 3; 
        }
    }
    
    // Set base cases for DP table
    for (int i = 0; i <= str1.size(); i++) {
        dp[i][0] = i * gap_penalty;
    }
    for (int j = 0; j <= str2.size(); j++) {
        dp[0][j] = j * gap_penalty;
    }
    
    // Fill DP table based on minimum cost calculations
    for (int i = 1; i <= str1.size(); i++) {
        for (int j = 1; j <= str2.size(); j++) {
            int match_or_mismatch = dp[i - 1][j - 1] + mismatch_cost[str1[i - 1] - 'a'][str2[j - 1] - 'a'];
            int gap_in_str1 = dp[i - 1][j] + gap_penalty;
            int gap_in_str2 = dp[i][j - 1] + gap_penalty;
            dp[i][j] = min({match_or_mismatch, gap_in_str1, gap_in_str2});
        }
    }
}

int main() {
    string str1 = "atgtg";
    string str2 = "atcgt";
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    
    calculateAlignmentCost(dp, str1, str2);

    cout << "Alignment cost table:" << endl;
    for (int i = 0; i <= str1.size(); i++) {
        for (int j = 0; j <= str2.size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
