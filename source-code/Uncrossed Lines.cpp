class Solution {
public:
    int solve(vector<int> &a,vector<int> &b,int i,int j,vector<vector<int>> &dp){
        if(i==a.size() || j==b.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j])return dp[i][j]=1+solve(a,b,i+1,j+1,dp);
        return dp[i][j]=max(solve(a,b,i+1,j,dp),solve(a,b,i,j+1,dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(nums1,nums2,0,0,dp);
    }
};
