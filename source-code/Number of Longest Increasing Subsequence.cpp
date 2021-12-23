class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n=a.size();
        vector<pair<int,int>>dp(n,{1,1});
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]>a[j]){
                    if(dp[i].first==dp[j].first+1){
                        dp[i].second+=dp[j].second;
                    }
                    if(dp[i].first<dp[j].first+1){
                        dp[i].first=dp[j].first+1;
                        dp[i].second=dp[j].second;
                    }
                }
            }
            mx=max(mx,dp[i].first);
        }
        int cnt=0;
        for(auto x: dp){
            if(x.first==mx)cnt+=x.second;
        }
        return cnt;
    }
};
