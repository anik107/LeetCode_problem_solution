class Solution {
public:
    int dp[202][20002];
    bool solve(vector<int>& nums,int n,int sum){
        if(sum==0)return 1;
        if(n<=0 || sum<=0)return 0;
        if(dp[n][sum]!=-1)return dp[n][sum];
        if(nums[n-1]>sum)return dp[n][sum]=solve(nums,n-1,sum);
        else return dp[n][sum]=solve(nums,n-1,sum)+solve(nums,n-1,sum-nums[n-1]);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto x: nums)sum+=x;
        if(sum&1)return false;
        memset(dp,-1,sizeof(dp));
        int x=solve(nums,n,sum/2);
        return x>0;
    }
};
