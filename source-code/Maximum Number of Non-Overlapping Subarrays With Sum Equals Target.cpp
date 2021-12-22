class Solution {
public:
    int maxNonOverlapping(vector<int>& a, int k) {
        multiset<int>s;
        s.insert(0);
        int sum=0;
        int cnt=0;
        int n=a.size();
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(s.find(sum-k)!=s.end()){
                cnt++;
                s.clear();
            }
            s.insert(sum);
        }
        return cnt;
    }
};
