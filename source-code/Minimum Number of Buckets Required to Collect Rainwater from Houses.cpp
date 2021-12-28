class Solution {
public:
    int minimumBuckets(string street) {
        int cnt=0;
        int res=0;
        for(int i=0;i<street.size();i++){
            if(street[i]=='H'){
                if(i+1<street.size() and street[i+1]=='.'){
                    cnt++;
                    i+=2;
                    continue;
                }
                if(i-1>=0 and street[i-1]=='.'){
                    cnt++;
                    continue;
                }
                return -1;
            }
        }
        return cnt;
    }
};
