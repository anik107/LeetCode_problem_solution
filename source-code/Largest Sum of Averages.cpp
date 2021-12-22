class Solution {
public:
    double solve(vector<int> &a,int pos,int n,int k,vector<vector<double>> &dp){
        if(pos==n)return 0;
        if(dp[pos][k]!=-1)return dp[pos][k];
        double mx=0;
        double sum=0;
        if(k==1){
            for(int i=pos;i<n;i++)sum+=a[i];
            return sum/(n-pos);
        }
        double avg,tmp;
        for(int i=pos;i<n;i++){
            sum+=a[i];
            avg=sum/(i-pos+1);
            tmp=avg+solve(a,i+1,n,k-1,dp);
            mx=max(mx,tmp);
        }
        return dp[pos][k]=mx;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<double>>dp(n,vector<double>(k+1,-1));
        return solve(nums,0,n,k,dp);
    }
};
