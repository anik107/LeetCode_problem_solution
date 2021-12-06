class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+2][n+2];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1 && j==1){dp[i][j]=1;continue;}
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
