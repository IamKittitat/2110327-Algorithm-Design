#include<iostream>
#include<vector>
#include<queue>

using namespace std;
const int INF = 1e9;
 
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < M; i++){
        int A, B, C;
        cin >> A >> B >> C;
        A--, B--;
        G[A].push_back({B, C});
    }
    vector<vector<int>> D(N, vector<int>(N, INF));
    for(int i = 0; i < N; i++){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto &p : G[i]){
            int v = p.first, c = p.second;
            D[i][v] = min(D[i][v], c);
            pq.push({D[i][v], v});
        }
        while(!pq.empty()){
            pair<int,int> t = pq.top();
            pq.pop();
            int d = t.first, u = t.second;
            if(d > D[i][u])continue;
            for(auto &p : G[u]){
                int v = p.first, c = p.second;
                if(v != i && D[i][v] > d + c){
                    D[i][v] = d + c;
                    pq.push({D[i][v], v});
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        int ans = D[i][i];
        for(int j = 0; j < N; j++){
            ans = min(ans, D[i][j] + D[j][i]);
        }
        cout << ((ans == INF) ? -1 : ans) << '\n';
    }

    // for(auto &x : D){
    //     for(auto &y : x) cout << y << " ";
    //     cout<< endl;
    // }
}