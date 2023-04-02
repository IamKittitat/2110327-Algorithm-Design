#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<long long>> w(n+1,vector<long long>(n+1,INT64_MAX));
    for(int i = 0;i<m;i++){
        long long a,b,c;
        cin >> a >> b >> c;
        w[a][b] = min(w[a][b],c);
        w[b][a] = min(w[b][a],c);
    }

    for(int i = 1;i<=n;i++) w[i][i] = 0;
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(w[i][k] != INT64_MAX && w[k][j] != INT64_MAX){
                    w[i][j] = min(w[i][j],w[i][k]+w[k][j]);
                }
            }
        }
    }
    for(int i = 0;i<q;i++){
        int s,d;
        cin >> s >> d;
        if(w[s][d] != INT64_MAX) cout << w[s][d] << "\n";
        else cout << "-1\n";
    }
}