class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        int n=a.size();
        int mx=0;
        vector<unordered_map<int,int>>dp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=a[i]-a[j];
                dp[i][diff]=(dp[j].count(diff)>0)?dp[j][diff]+1:2;
                mx=max(mx,dp[i][diff]);
            }
        }
        return mx;
    }
};
