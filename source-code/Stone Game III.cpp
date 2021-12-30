class Solution {
public:
    int dp[50005][2][2];
    int solve(vector<int>& a,bool alice, bool bob, int i) {
        if(i>=a.size())return 0;
        if (dp[i][alice][bob]!=-1)return dp[i][alice][bob];
        int ans;
        int sum=0;
        if(alice){
            ans=INT_MIN;
            for (int j=i;j<i+3 && j<a.size();j++) {
                sum+=a[j];
                ans=max(ans, sum+solve(a,false,true,j+1));
            }
        }
        if(bob){
            ans=INT_MAX;
            for (int j=i;j<i+3 && j<a.size();j++) {
                ans=min(ans, solve(a,true,false,j+1));
            }
        }
        return dp[i][alice][bob]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(auto x: stoneValue)sum+=x;
        int alice=solve(stoneValue,true,false,0);
        if(sum-alice>alice)return "Bob";
        else if(sum-alice<alice)return "Alice";
        else return "Tie";
    }
};
