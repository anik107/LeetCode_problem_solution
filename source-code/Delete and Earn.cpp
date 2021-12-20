class Solution {
public:
    int dp[200005];
    int solve(vector<int>& a,int i){
        if(i>=a.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int cur=a[i];
        int sum=a[i];
        int idx=i+1;
        while(idx<a.size() && cur==a[idx]){
            sum+=a[i];
            idx++;
        }
        while(idx<a.size() && a[idx]==cur+1)idx++;
        return dp[i]=max(sum+solve(a,idx),solve(a,i+1));
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};
