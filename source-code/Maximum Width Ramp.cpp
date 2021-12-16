class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int>s;
        s.push(0);
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[s.top()])s.push(i);
        }
        int ans=0;
        for(int i=nums.size()-1;i>=0;i--){
            while(!s.empty() && nums[i]>=nums[s.top()]){
                ans=max(ans,i-s.top());
                s.pop();
            }
        }
        return ans;
    }
};
