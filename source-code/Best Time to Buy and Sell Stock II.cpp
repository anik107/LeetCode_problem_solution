class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=0,j=0;
        int sum=0;
        while(i<n && j<n){
            while(i<n-1 && prices[i+1]<prices[i])i++;
            j=i;
            while(j<n-1 && prices[j+1]>prices[j])j++;
            sum+=prices[j]-prices[i];
            i=j+1;
        }
        return sum;
    }
};
