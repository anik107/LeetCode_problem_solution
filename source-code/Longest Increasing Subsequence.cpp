class Solution {
public:
    int tree[100005];
    void init(){
        memset(tree,0,sizeof(tree));
    }
    void update(int idx,int val,int n){
        while(idx<=n){
            tree[idx]=max(tree[idx],val);
            idx+=idx&-idx;
        }
    }
    int query(int idx){
        int mx=0;
        while(idx>0){
            mx=max(mx,tree[idx]);
            idx-=idx&-idx;
        }
        return mx;
    }
    int lengthOfLIS(vector<int>& a) {
        init();
        int n=a.size();
        vector<int>b;
        for(int i=0;i<n;i++){
            b.push_back(a[i]);
        }
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        vector<int>c;
        for(int i=0;i<n;i++){
            c.push_back(lower_bound(b.begin(),b.end(),a[i])-b.begin()+1);
        }
        int mx=0;
        for(auto x: c){
            update(x,query(x-1)+1,n);
            mx=max(mx,query(x));
        }
        return mx;
    }
};
