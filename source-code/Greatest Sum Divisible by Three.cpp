class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>dp{0,0,0};
        for(auto x: nums){
            vector<int>v=dp;
            for(auto y: dp){
                int z=x+y;
                v[z%3]=max(z,v[z%3]);
            }
            dp=v;
        }
        return dp[0];
    }
};
