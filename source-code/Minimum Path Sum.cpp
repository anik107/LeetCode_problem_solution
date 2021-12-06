class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dp[n+2][m+2];
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i==n || j==m)dp[i][j]=1e6;
                else if(i==n-1 && j==m-1)dp[i][j]=grid[i][j];
                else {
                    dp[i][j]=min(dp[i+1][j]+grid[i][j],dp[i][j+1]+grid[i][j]);
                }
            }
        }
        return dp[0][0];
    }
};
