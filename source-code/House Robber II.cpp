class Solution {
public:
    int solve(vector<int>& nums){
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();        
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        vector<int>v1(nums.begin(),nums.end()-1);
        vector<int>v2(nums.begin()+1,nums.end());
        return max(solve(v1),solve(v2));
    }
};
