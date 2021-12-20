int cnt;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
       cnt=0;
        return call(nums,0 ,0 ,S);
    }
    int call(vector<int>& v,int i,int sum,int s)
    {
        if(i==v.size())
        {
            if(s==sum)
                cnt++;
        }
        else
        {
            call(v,i+1,sum+v[i],s);
            call(v,i+1,sum-v[i],s);
        }
        return cnt;
    }
};
