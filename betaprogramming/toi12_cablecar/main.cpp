#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n+1);
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    int s,d,p;
    cin >> s >> d >> p;
    vector<int> dist(n+1,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
    dist[s] = INT32_MAX;
    pq.push({dist[s],s});
    while(!pq.empty()){
        pair<int,int> t = pq.top();
        pq.pop();
        int w = t.first, v = t.second;
        for(auto &u : g[v]){
            if(dist[u.first] < min(u.second,w)){
                dist[u.first] = min(u.second,w);
                pq.push({dist[u.first],u.first});
            }
        }
    }
    // for(auto &x : dist) cout << x << " ";
    cout << ceil((float)p/(float)(dist[d]-1));
}