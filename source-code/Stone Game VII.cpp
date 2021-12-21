class Solution {
public:
    int dp[1005][1005];
    int solve(vector<int>& a,int i,int j,int sum){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int front=sum-a[i]-solve(a,i+1,j,sum-a[i]);
        int back=sum-a[j]-solve(a,i,j-1,sum-a[j]);
        return dp[i][j]=max(front,back);
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(auto x: stones)sum+=x;
        return solve(stones,0,n-1,sum);
    }
};
