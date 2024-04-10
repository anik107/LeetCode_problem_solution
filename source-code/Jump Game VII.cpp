#include<bits/stdc++.h>
using namespace std;
struct node{
    int x;
    int step;
};
int main(){
    vector<int>v{2,3,1,1,4};
    vector<bool>visit;
    for(int i=0;i<10005;i++)visit[i]=false;
    queue<node>q;
    node now;
    now.x=0;
    now.step=0;
    q.push(now);
    while(!q.empty()){
        now=q.front();
        q.pop();
        if(now.x>=v.size()-1)cout<<now.step<<endl;
        node next;
        for(int i=1;i<=v[now.x];i++){
            if(visit[now.x])continue;
            next.x=now.x+i;
            next.step=now.step+1;
            q.push(next);
            visit[next.x]=true;
        }
    }
}
