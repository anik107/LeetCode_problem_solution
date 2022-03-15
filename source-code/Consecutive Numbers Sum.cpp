class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int cnt=1;
        for(int i=2;i*(i+1)/2<=n;i++)if((n-i*(i+1)/2)%i==0)cnt++;
        return cnt;
    }
};
