#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int MOD = 1000000007;

    vector<int> dp(n+1);
    dp[0] = 1;

    for(int coin : money) {
        for(int c=coin; c<=n; c++) {
            dp[c] += dp[c - coin];
            dp[c] %= MOD;
        }
    }

    return dp[n];
}

int main() {
    return 0;
}