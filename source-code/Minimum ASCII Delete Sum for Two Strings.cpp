class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)dp[i][j]=0;
                else{
                    if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+s1[i-1];
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)sum+=s1[i];
        for(int i=0;i<m;i++)sum+=s2[i];
        return sum-2*dp[n][m];
    }
};
