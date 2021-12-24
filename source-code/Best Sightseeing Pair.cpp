class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int n=a.size();
        int left=a[0];
        int ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans,left+a[i]-i);
            left=max(left,a[i]+i);
        }
        return ans;
    }
};
