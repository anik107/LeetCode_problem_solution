class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        vector<int>dp(n,1);
        vector<int>p(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]%a[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    p[i]=j;
                }
            }
        }
        int id;
        int mx=-1;
        for(int i=0;i<n;i++){
            if(mx<dp[i]){
                mx=dp[i];
                id=i;
            }
        }
        vector<int>ans;
        while(id>=0 && mx--){
            ans.push_back(a[id]);
            id=p[id];
        }
        return ans;
    }
};
