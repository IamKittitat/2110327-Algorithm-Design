#include<iostream>
#include<vector>

using namespace std;

int n,e;
vector<vector<int>> g;
vector<int> sol;

bool solve(int v,int color){
    if(v == n) return true;

    for(int i = 0;i<color;i++){
        bool can = true;
        for(auto &u : g[v]){
            if( u < v && sol[u] == i) can = false;
        }
        if(can){
            sol[v] = i;
            if(solve(v+1,color)) return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> e;
    g.resize(n);

    for(int i = 0;i<e;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1;i<=n;i++){
        sol.resize(n,-1);
        sol[0] = 0;
        if(solve(0,i)){
            cout << i;
            break;
        }
    }
}