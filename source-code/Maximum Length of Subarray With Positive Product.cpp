class Solution {
public:
    int getMaxLen(vector<int>& a) {
        int n=a.size();
        vector<int>pos(n+1,0);
        vector<int>neg(n+1,0);
        int mx=0;
        for(int i=1;i<=n;i++){
            if(a[i-1]<0){
                pos[i]=pos[i-1];
                neg[i]=neg[i-1]+1;
            }
            if(a[i-1]>0){
                pos[i]=pos[i-1]+1;
                neg[i]=neg[i-1];
            }
            if(a[i-1]==0){
                pos[i]=neg[i]=0;
            }
            if(neg[i]%2==0)mx=max(mx,pos[i]+neg[i]);
        }
        pos[n]=0;
        neg[n]=0;
        for(int i=n-1;i>=0;i--){
            if(a[i]<0){
                pos[i]=pos[i+1];
                neg[i]=neg[i+1]+1;
            }
            if(a[i]>0){
                pos[i]=pos[i+1]+1;
                neg[i]=neg[i+1];
            }
            if(a[i]==0){
                pos[i]=0;
                neg[i]=0;
            }
            if(neg[i]%2==0)mx=max(mx,pos[i]+neg[i]);
        }
        return mx;
    }
};
