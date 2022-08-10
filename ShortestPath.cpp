#include <bits/stdc++.h>

using std::priority_queue;
using std::vector;
using std::array;
using std::pair;
using std::make_pair;
using std::cin;
using std::cout;
using std::endl;

const int N=1e3+5;
const int inf=1e9;

class Compare{
public:
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        return a.first>b.first;//从小到大
    }
};

int Dijkstra(int s,int t,const vector<vector<pair<int,int>> > &edges){
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> que;
    array<int,N>dis;
    dis.fill(inf);
    que.push(make_pair(0,s));
    dis[s]=0;
    while(!que.empty()){
        pair<int,int> tmp=que.top();
        que.pop();
        if(dis[tmp.second]<tmp.first)
            continue;
        for(auto x:edges[tmp.second]){
            if(dis[x.second]>dis[tmp.second]+x.first){
                dis[x.second]=dis[tmp.second]+x.first;
                que.push(make_pair(dis[x.second],x.second));
            }
        }
    }
    return dis[t]<inf?dis[t]:-1;
}

int main(){
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    vector<vector<pair<int,int>> > edges;
    edges.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        edges[u].push_back(std::make_pair(w,v));
        edges[v].push_back(std::make_pair(w,u));
    }
    int ans=Dijkstra(s,t,edges);
    cout<<ans<<endl;
    return 0;
}