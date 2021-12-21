class Solution {
public:
    int dp[100005];
    int solve(vector<int>& a,int s,int k){
        if(s>=a.size())return 0;
        if(dp[s]!=-1)return dp[s];
        int mx=0;
        int mxsum=0;
        for(int i=s;i<min((int)a.size(),s+k);i++){
            mx=max(mx,a[i]);
            mxsum=max(mxsum,solve(a,i+1,k)+mx*(i-s+1));
        }
        return dp[s]=mxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,k);
    }
};
