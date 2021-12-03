class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)return 1;
        set<long long>s;
        s.insert(1);
        n--;
        while(!s.empty() && n>0){
            long long x=*s.begin();
            s.erase(s.begin());
            s.insert(x*2);
            s.insert(x*3);
            s.insert(x*5);
            n--;
        }
        return *s.begin();
    }
};
