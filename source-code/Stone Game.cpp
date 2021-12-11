class Solution {
public:
    int dp[1005][1005];
    int solve(int l,int r,vector <int> &piles) {
        if(l==r-1) return max(piles[l],piles[r]);
        if(dp[l][r]!=-1)return dp[l][r];
        int x=piles[l]+max(solve(l+2,r,piles),solve(l+1,r-1,piles));
        int y=piles[r]+max(solve(l+1,r-1,piles),solve(l,r-2,piles));
        return dp[l][r]=max(x,y);
    }
    bool stoneGame(vector<int>& piles) {
        int l=0, r=piles.size()-1;
        memset(dp,-1,sizeof(dp));
        int alex=solve(l, r, piles);
        int sum=0;
        for(int i=0;i<piles.size();i++)sum+=piles[i];
        return alex>(sum-alex);
    }
};
