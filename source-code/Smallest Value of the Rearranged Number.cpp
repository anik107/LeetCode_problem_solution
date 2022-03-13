class Solution {
public:
    long long smallestNumber(long long num) {
        string s=to_string(num);
        int cnt[10]={0};
        int sig=s[0]-'0';
        if(sig>=0 && sig<=9){
            for(auto x: s){
                int d=x-'0';
                if(d>=0 && d<=9)cnt[d]++;
            }
            string ans="";
            for(int i=1;i<=9;i++){
                if(cnt[i]!=0){
                    for(int j=0;j<cnt[i];j++)ans.push_back(i+'0');
                }
            }
            string ss="";
            if(cnt[0]!=0){
               for(int i=0;i<cnt[0];i++)ss.push_back('0');
               if(ans.size()>0)ans.insert(1,ss);
            }
            long long n=0;
            for(auto x: ans)n=n*10+(x-'0');
            return n;
        }
        else{
            string ans="";
            for(int i=1;i<s.size();i++){
                int d=s[i]-'0';
                if(d>=0 && d<=9)cnt[d]++;
            }
            for(int i=9;i>=0;i--){
                if(cnt[i]!=0){
                    for(int j=0;j<cnt[i];j++)ans.push_back(i+'0');
                }
            }
            long long n=0;
            for(auto x: ans)n=n*10+(x-'0');
            return (-1)*n;
        }
    }
};
