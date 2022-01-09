class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int>mp;
        for(auto i: nums1){
            for(auto j: nums2){
                mp[i+j]++;
            }
        }
        vector<int>v;
        for(auto x: nums3){
            for(auto y: nums4)v.push_back(x+y);
        }
        int cnt=0;
        for(auto x: v)cnt+=mp[-x];
        return cnt;
    }
};
