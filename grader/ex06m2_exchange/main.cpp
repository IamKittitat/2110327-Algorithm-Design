#include<iostream>
#include<vector>

using namespace std;


// Floyd-Warshall Algorithm to find >1 cycle
int main(){
    int k;
    cin >> k;
    for(int x = 0 ; x < k;x++){
        int n;
        cin >> n;
        // In-place calculation
        vector<vector<float>> v(n,vector<float>(n,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++) cin >> v[i][j];
        }

        // Do FW for n times
        for(int k = 0;k<n;k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    v[i][j] =max(v[i][j],v[i][k]*v[k][j]);
                }
            }
        }

        // IF v[i][i] > 1 then it's infinite loop
        bool found = false;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i == j && v[i][j] > 1) found = true;
            }
        }
        if(found) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*
2
3
1 0.7 1.2
1.1 1 2
0.75 0.7 1 
2
1 0.7
1.2 1
*/