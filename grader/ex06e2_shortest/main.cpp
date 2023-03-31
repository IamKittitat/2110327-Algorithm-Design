#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,e,s;
    cin >> n >> e >> s;
    vector<pair<int,pair<int,int>>> E(e);
    for(int i = 0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        E[i] = {c,{a,b}};
    }
    vector<int> dist(n,1000000);
    dist[s] = 0;
    for(int k = 1;k<n;k++){
        for(auto &edge : E){
            int w = edge.first, from = edge.second.first, to = edge.second.second;
            dist[to] = min(dist[to],dist[from] + w);
        }
    }

    bool negCycle = false;
    for(auto &edge : E){
        int w = edge.first, from = edge.second.first, to = edge.second.second;
        if(dist[from] + w < dist[to]) negCycle = true;
    }
    if(negCycle) cout << -1;
    else for(auto &x : dist) cout << x << " ";

}