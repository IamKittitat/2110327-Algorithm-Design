#include <iostream>
#include<vector>
#include<algorithm>

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
    int maxa = va[k-1];
    if(maxa < minb) cout << "YES";
    else cout << "NO";
}
