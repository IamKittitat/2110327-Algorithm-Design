#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> deg(n,0);
    for(int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    queue<int> leaves;
    for(int i = 0;i<n;i++){
        if(deg[i] == 1){
            leaves.push(i);
            deg[i] = 0;
        }
    }
    while(!leaves.empty()){
        int t = leaves.front();
        leaves.pop();
        for(auto &u : g[t]){
            deg[u]--;
            if(deg[u] == 1){
                leaves.push(u);
                deg[u] = 0;
            }
        }
    }
    int ans = 0;
    for(auto &x : deg) if(x > 0) ans++;
    cout << ans;
}
