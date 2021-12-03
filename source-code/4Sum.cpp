class Solution {
public:
    typedef long long ll;
    vector<vector<ll>> fourSum(vector<ll>& nums, ll target) {
        vector<vector<int>> res;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        if(nums.size()<4)return res;
        for(int i=0;i<nums.size()-3;i++){
            for(int j=i+1;j<nums.size()-2;j++){
                int left=j+1;
                int right=nums.size()-1;
                while(left<right){
                    ll cur=nums[i]+nums[j]+nums[left]+nums[right];
                    if(cur==target)s.insert({nums[i],nums[j],nums[left],nums[right]});
                    if(cur<=target)left+=1;
                    if(cur>=target)right-=1;
                }
            }
        }
        for(auto x: s)res.push_back(x);
        return res;
    }
};
