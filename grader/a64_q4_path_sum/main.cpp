#include<iostream>
#include<vector>
#include<map>

using namespace std;

int n,m, ub = 0;
vector<vector<pair<int,int>>> g;
vector<int> ki(8);
vector<int> maxIn;

bool dfs(vector<int> &color,int v,int total,int needed,int ub){
    if(total == needed) return true;
    if(total > needed) return false;
    if(total + ub < needed) return false;

    color[v] = 1;
    for(auto &u : g[v]){
        if(color[u.first] == 0){
            color[u.first] = 1;
            if(dfs(color,u.first,total+u.second,needed,ub-maxIn[u.first])) return true;
            color[u.first] = 0;
        }   
    }
    color[v] = 0;
    return false;
}

void dfs_all(int needed){
    vector<int> color(n,0);
    int total;
    for(int i = 0;i<n;i++){
        if(color[i] == 0){
            if(dfs(color,i,0,needed,ub-maxIn[i])){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); 
    cin >> n >> m;
    g.resize(n);
    maxIn.resize(n,-1);
    for(int i = 0;i<8;i++) cin >> ki[i];
    for(int i = 0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
        maxIn[a] = max(maxIn[a],w);
        maxIn[b] = max(maxIn[b],w);
    }
    for(auto &x : maxIn) ub += x;

    for(int i = 0;i<8;i++){
        dfs_all(ki[i]);
    }
}