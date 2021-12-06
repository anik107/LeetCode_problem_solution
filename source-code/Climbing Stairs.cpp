class Solution {
public:
    int climbStairs(int n) {
        int dp[n+2];
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+(i-2<0?0:dp[i-2]);
        }
        return dp[n];
    }
};
