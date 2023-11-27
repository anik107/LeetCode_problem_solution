#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    int i=0,j=n-1;
    int area =0;
    while(i<j){
        area=max(area,(j-i)*min(a[i],a[j]));
        if(a[i]<=a[j])i++;
        else j--;
    }
    cout<<area<<endl;
}