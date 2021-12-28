class Solution {
public:
      int solve(vector<vector<int>>& v,int h,int j,vector<vector<int>> &dp) {
        if(h==v.size())return 0;
        if(dp[h][j]!=-1)return dp[h][j];  
        return dp[h][j]=v[h][j]+min(solve(v,h+1,j,dp),solve(v,h+1,j+1,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int h=triangle.size();
        int j=h;
        vector<vector<int>>dp(h,vector<int> (j,-1));
        return solve(triangle,0,0,dp);  
    }
};
