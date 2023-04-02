#include<iostream>
#include<vector>

using namespace std;

typedef pair<int,pair<int,int>> edge;

int maxIdx(vector<int> &dist){
    int idx = -1, maxVal = INT32_MIN;
    for(int i = 0;i<dist.size();i++){
        if(dist[i] > maxVal){
            maxVal = dist[i];
            idx = i;
        }
    }
    return idx;
}

int main(){
    int n;
    cin >> n;
    vector<int> b(n);
    for(int i = 0;i<n;i++) cin >> b[i];
    vector<int> dist(n,INT32_MIN);
    vector<bool> inMST(n,false);
    dist[0] = 0;
    unsigned long long ans = 0;
    for(int i = 0;i<n;i++){
        int u = maxIdx(dist);
        ans += (unsigned long long) dist[u];
        dist[u] = INT32_MIN;
        inMST[u] = true;
        for(int j = 0;j<n;j++){
            if(!inMST[j] && dist[j] < (b[u]^b[j])){
                dist[j] = b[u] ^ b[j];
            }
        }
    }
    cout << ans;
}