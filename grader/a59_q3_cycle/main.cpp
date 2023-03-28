#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void get_leaves(queue<int> &leaves,vector<int> &deg){
    for(int i = 0;i<deg.size();i++){ 
        if(deg[i] == 1) {
            leaves.push(i);
            deg[i]--;
        }
    }
}

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
    }

    queue<int> leaves;
    for(int i = 0;i<n;i++) deg[i] = g[i].size();

    get_leaves(leaves,deg);

    while(!leaves.empty()){
        int f = leaves.front();
        leaves.pop();
        for(auto &u : g[f]){ 
            deg[u]--;
            if(deg[u] == 1){
                leaves.push(u);
                deg[u]--;
            }
        }
        // for(auto &x : deg) cout << x << " ";
        // cout << endl;
    }
    int ans = 0;
    // for(auto &d : deg) cout << d << " ";
    // cout << endl;
    for(auto &d : deg) if(d > 0) ans++;
    cout << ans;
}