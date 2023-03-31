#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class DSU{
    private:
        vector<int> parent;
    public:
        DSU(int n){
            parent.resize(n);
            for(int i = 0;i<n;i++) parent[i] = i;
        }
        int findRoot(int u){
            if(parent[u] != u){
                parent[u] = findRoot(parent[u]);
            }
            return parent[u];
        }
        bool join(int u,int v){
            int pu = findRoot(u);
            int pv = findRoot(v);
            if(pu != pv){
                parent[pu] = pv;
                return true;
            } else{
                return false;
            }
        }
};

typedef pair<int,pair<int,int>> kruskalPair;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n,m,q;
    cin >> n >> m >> q;
    vector<kruskalPair> edges(m);
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges[i] = {c,{a,b}};
    }
    DSU dsu(n);
    sort(edges.begin(),edges.end());
    vector<int> ans;
    for(auto &e : edges){
        if(dsu.join(e.second.first,e.second.second)){
            ans.push_back(e.first);
        }
    }
    for(int i = 0 ;i<q;i++){
        int ip;
        cin >> ip;
        cout << ans[ans.size()-ip] << "\n";
    }
}


// Use Prim to find MST and store selected edge in the vector (0.5 SEC AND A LOT OF MEMORY)
// int main(){
//     int n,m,q;
//     cin >> n >> m >> q;
//     vector<vector<int>> v(n,vector<int>(n,INT32_MAX));
//     for(int i = 0;i<m;i++){
//         int a,b,c;
//         cin >> a >> b >> c;
//         v[a][b] = c;
//         v[b][a] = c;
//     }

//     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
//     vector<bool> inMST(n,false);
//     vector<int> dist(n,INT32_MAX);
//     vector<pair<int,pair<int,int>>> edge;
//     dist[0] = 0;
//     pq.push({dist[0],{0,0}});
//     while(!pq.empty()){
//         pair<int,pair<int,int>> p = pq.top();
//         pq.pop();
//         int d = p.first, u = p.second.first, to = p.second.second;
//         if(!inMST[to]){
//             inMST[to] = true;
//             edge.push_back({d,{u,to}});
//             for(int i = 0;i<n;i++){
//                 if(v[to][i] < dist[i] && !inMST[i]){
//                     dist[i] = v[to][i];
//                     pq.push({dist[i],{to,i}});
//                 }
//             }
//         }
//     }
//     sort(edge.begin(),edge.end());
//     for(int i = 0;i<q;i++){
//         int ip;
//         cin >> ip;
//         cout << edge[edge.size()-ip].first << "\n";
//     }
// }

/*
5 6 4
0 1 20
0 2 10
2 3 30
1 3 10
2 4 40
3 4 50
1
2
3
4
*/