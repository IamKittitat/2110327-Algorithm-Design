#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class DSU{
    private:
        vector<int> parent;
    public:
        DSU(int n){
            parent.resize(n+1);
            for(int i = 0;i<=n;i++) parent[i] = i;
        }
        int findRoot(int u){
            if(parent[u] != u){
                parent[u] = findRoot(parent[u]);
            }
            return parent[u];
        }

        bool joinSet(int u,int v){
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

typedef pair<int,pair<int,int>> edge;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    DSU dsu(n);
    priority_queue<edge> pq;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        pq.push({c,{a,b}});
    }
    long long ans = 0;
    int count = 0;
    while(count < n-1){
        edge t = pq.top();
        pq.pop();
        long long l = t.first, from = t.second.first, to = t.second.second;
        if(dsu.joinSet(from,to)){
            count++;
            ans += l-1;
        }
    }
    cout << ans;
}   