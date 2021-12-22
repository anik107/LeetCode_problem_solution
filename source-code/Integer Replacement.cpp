class Solution {
public:
    int solve(int n){
        if(n==INT_MAX)return 32;
        if(n==1)return 0;
        if(n==3)return 2;
        if (n & 1)return n%4==3?1+solve(n+1):1+solve(n-1);
        return 1+solve(n/2);
    }
    int integerReplacement(int n) {
       return solve(n); 
    }
};
