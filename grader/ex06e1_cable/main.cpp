#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int,pair<int,int>> kruskalPair;

// PRIM ALGORITHM
int prim(vector<vector<int>> w,int n){
    vector<int> dist(n,INT32_MAX);
    vector<bool> inMST(n,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[0] = 0;
    int ans = 0;
    pq.push({dist[0],0});
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        // cout << p.first << endl;
        int v = p.second;
        if(!inMST[v]){
            inMST[v] = true;
            ans += dist[v];
            for(int i = 0;i<n;i++){
                if(w[v][i] >= 0 && w[v][i] < dist[i] && !inMST[i]){
                    dist[i] = w[v][i];
                    pq.push({dist[i],i});
                }
            }
        }
    }
    return ans;
}

// KRUSKAL ALGORITHM
int findSet(vector<int> &dju, int n){
    while(dju[n] != n) n = dju[n];
    return n;
}

void unionSet(vector<int> &dju,int i, int j){
    int u = findSet(dju,i), v = findSet(dju,j);
    dju[u] = v;
}

int kruskal(vector<vector<int>> w,int n){
    priority_queue<kruskalPair,vector<kruskalPair>,greater<kruskalPair>> pq;
    vector<int> dju(n);
    for(int i = 0;i<n;i++) dju[i] = i;
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++) if(w[i][j] >= 0) pq.push({w[i][j],{i,j}});
    }

    int count = 0, ans = 0;
    while(count < n-1){
        kruskalPair p = pq.top();
        int w = p.first, i = p.second.first, j = p.second.second;
        pq.pop();
        if(findSet(dju,i) != findSet(dju,j)){
            count++;
            ans += w;
            unionSet(dju,i,j);
        }
    }
    return ans;        
}
// ---------------------------------

int main(){
    int n;
    cin >> n;
    vector<vector<int>> w(n,vector<int>(n,-1));
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            int ip;
            cin >> ip;
            w[i][j] = ip;
            w[j][i] = ip;
        }
    }
    // cout << prim(w,n);
    cout << kruskal(w,n);
}

/*
4
1 3 4
2 7 
6
*/ 