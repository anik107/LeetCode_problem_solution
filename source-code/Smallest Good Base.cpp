class Solution {
public:
    typedef unsigned long long ll;
    string smallestGoodBase(string n) {
       ll num=stoll(n);
       ll mn=2,mx=log2(1.0*num);
       for(int i=mx;i>=mn;i--){
        ll k=pow(num,1.0/i);
        if(k<2)continue;
        ll sum=0;
        ll mul=1;
        for(int j=0;j<=i;j++){
            sum+=mul;
            mul*=k;
        }
        if(sum==num){
            return to_string(k);
        }
       }
        return to_string(num-1);
    }
};
