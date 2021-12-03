class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        auto cmp=[](const int a,const int b){
            return a>b;
        };
        multiset<int,decltype(cmp)>s(cmp);
        for(auto x: piles)s.insert(x);
        while(k-->0){
            auto it=s.begin();
            int x=*it;
            s.erase(it);
            if(x&1)s.insert(x/2+1);
            else s.insert(x/2);
        }
        int sum=0;
        for(auto x: s)sum+=x;
        return sum;
    }
};
