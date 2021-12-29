class Solution {
public:
    bool solve(int n){
        if(n==1)return true;
        if(n%4==0 && n>=4) return solve(n/4);
        else return false;
    }
    bool isPowerOfFour(int n) {
        return solve(n);
    }
};
