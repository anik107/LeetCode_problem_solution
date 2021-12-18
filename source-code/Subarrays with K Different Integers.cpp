class Solution {
public:
    int solve(vector<int>& a,int k){
        int n=a.size();
        int sum=0;
        int j=0;
        int ans=0;
        int cnt[500005]={0};
        for(int i=0;i<n;i++){
            if(cnt[a[i]]==0){
                sum++;
            }
            cnt[a[i]]++;
            while(j<n && sum>k){
                cnt[a[j]]--;
                if(cnt[a[j]]==0)sum--;
                j++;
            }
            ans+=i-j+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& a, int k) {
       return solve(a,k)-solve(a,k-1);
    }
};
