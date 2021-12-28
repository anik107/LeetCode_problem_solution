class Solution {
public:
    int dp[71][10000];
    int solve(vector<vector<int>>&mat,int row,int sum,int target){   
        if(row>=mat.size())return abs(sum-target);
        if(dp[row][sum] != -1)return dp[row][sum];
        int ans=INT_MAX;
        for(int i=0;i<mat[row].size();i++){
            ans=min(ans,solve(mat,row+1,sum+mat[row][i],target));
        }
        return dp[row][sum]=ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(mat,0,0,target);
        
    }
};
