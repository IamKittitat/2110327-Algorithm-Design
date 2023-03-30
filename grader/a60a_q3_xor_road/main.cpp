#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> w(n,vector<int>(n,0));
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++) w[i][j] = v[i]^v[j];
    }

    vector<int> dist(n,-1);
    vector<bool> inMST(n,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
    dist[0] = 0;
    pq.push({dist[0],0});
    unsigned long long ans = 0;
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        int d = p.first, v = p.second;
        if(!inMST[v]){
            inMST[v] = true;
            ans = ans + (unsigned long long) d;
            for(int i = 0;i<n;i++){
                if(w[v][i] > 0 && w[v][i] > dist[i] && !inMST[i]){
                    dist[i] = w[v][i];
                    pq.push({dist[i],i});
                }
            }
        }
    }
    cout << ans;
}