class Solution
{
public:
    int minDistance(string s, string t)
    {
        int len1=s.size();
        int len2=t.size();
        int a[len1+5][len2+5];
        memset(a,0,sizeof a);
        for(int i=1; i<=len1; i++)
            a[i][0]=i;
        for(int i=1; i<=len2; i++)
            a[0][i]=i;



        for(int i=1; i<=len1; i++)
        {
            for(int j=1; j<=len2; j++)
            {
                int m=(s[i-1]==t[j-1]) ? 0:1;
                int temp=min(a[i-1][j]+1,a[i][j-1]+1);
                a[i][j]=min(temp,a[i-1][j-1]+m);
            }
        }
        return a[len1][len2];
    
