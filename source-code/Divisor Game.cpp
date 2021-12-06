class Solution {
public:
    bool divisorGame(int n) {
        bool dp[n+2];
        memset(dp,false,sizeof(dp));
        for(int i=2;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                if(i%j==0 && !dp[i-j])dp[i]=true;
            }
        }
        return dp[n];
    }
};
