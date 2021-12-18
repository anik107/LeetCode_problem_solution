class Solution {
public:
    int minSubArrayLen(int k, vector<int>& a) {
        int n=a.size();
        int sum=0;
        int j=0;
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=a[i];
            while(j<n && sum>=k){
                if(sum>=k)mn=min(mn,i-j+1);
                sum-=a[j];
                j++;
            }
        }
        return (mn==INT_MAX)?0:mn;
    }
};
