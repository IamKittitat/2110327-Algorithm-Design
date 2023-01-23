#include <bits/stdc++.h>

using namespace std;

int main()
{
    int na,nb,k,m;
    cin >> na >> nb;
    cin >> k >> m;
    vector<int> va(na),vb(nb);
    for(int i = 0; i < na;i++) cin >> va[i];
    for(int i = 0; i< nb;i++) cin >> vb[i];
    int minb = vb[vb.size()-m];
    bool can = true;
    for(int i = 0;i<k;i++){
        if(va[i] >= minb){
            can = false;
            break;
        }
    }
    if(can) cout << "YES";
    else cout << "NO";
}
