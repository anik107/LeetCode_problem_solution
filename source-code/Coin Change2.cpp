class Solution {
public:
    int dp[305][5005];
    int solve(vector<int>& a,int n,int sum){
        if(n==0)return 0;
        if(sum==0)return 1;
        if(dp[n][sum]!=-1)return dp[n][sum];
        if(a[n-1]>sum){
            return dp[n][sum]=solve(a,n-1,sum);
        }
        return dp[n][sum]=solve(a,n,sum-a[n-1])+solve(a,n-1,sum);
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        int n=coins.size();
        return solve(coins,n,amount);
    }
};
