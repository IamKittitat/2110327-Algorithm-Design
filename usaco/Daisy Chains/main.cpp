#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,ans=0;;
    cin >> n;
    vector<double> v(n);
    for(int i = 0 ;i<n;i++) cin >> v[i];
    for(int i = 0;i<v.size();i++){
        for(int j = i ;j<v.size();j++){
            double tmp = 0;
            for(int k = i;k<=j;k++) tmp += v[k];
            tmp /= (j-i+1);
            for(int k = i;k<=j;k++) if(v[k] == tmp) {ans++;break;}
        }
    }
    cout << ans;
}
