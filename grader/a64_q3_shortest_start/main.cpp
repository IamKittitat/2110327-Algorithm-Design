#include<iostream>
#include<vector>

using namespace std;

typedef pair<int,pair<int,int>> edge;

// BELLMAN-FORD K times O(vek) 50/100
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    int v;
    cin >> v;
    vector<int> start(k);
    vector<edge> g(n);
    for(int i = 0;i<k;i++) cin >> start[i];
    for(int i = 0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        g.push_back({w,{b,a}});
    }
    
    vector<int> dist(n,INT32_MAX);
    for(k = 1;k<n;k++){
        dist[v] = 0;
        for(auto &e : g){
            int w = e.first, from = e.second.first, to = e.second.second;
            if(dist[from] != INT32_MAX) dist[to] = min(dist[to],dist[from] + w);
        }
    }
    int ans = INT32_MAX;
    // for(auto &x : dist) cout << x << " ";
    for(auto &s : start) ans = min(ans,dist[s]);
    cout << ans;
}


// FLOYD-WARSHALL O(v**3) 35/100
// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     int n,m,k;
//     cin >> n >> m >> k;
//     int v;
//     cin >> v;
//     vector<int> start(k);
//     vector<edge> g(n);
//     vector<vector<int>> dist(n,vector<int>(n,INT32_MAX));
//     for(int i = 0;i<n;i++) dist[i][i] = 0;
//     for(int i = 0;i<k;i++) cin >> start[i];
//     for(int i = 0;i<m;i++){
//         int a,b,w;
//         cin >> a >> b >> w;
//         g.push_back({w,{a,b}});
//         dist[a][b] = w;
//     }

//     for(int k = 0;k<n;k++){
//         for(int i = 0;i<n;i++){
//             for(int j = 0;j<n;j++){
//                 if(dist[i][k] != INT32_MAX && dist[k][j] != INT32_MAX){
//                     dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
//                 }
//             }
//         }
//     }
//     int ans = INT32_MAX;
//     for(auto &s : start){
//         ans = min(ans,dist[s][v]);
//     }
//     cout << ans;
// }