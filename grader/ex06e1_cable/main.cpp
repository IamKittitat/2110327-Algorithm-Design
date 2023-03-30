#include<iostream>
#include<vector>
#include<queue>

using namespace std;

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

    vector<int> dist(n,INT32_MAX);
    vector<bool> inMST(n,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[0] = 0;
    int ans = 0;
    // for(int i = 0;i<n;i++) pq.push({dist[i],i});
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
    cout << ans;
}

/*
4
1 3 4
2 7 
6
*/