#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,ans=0;
    cin >> n >> m;
    int limit = max(n,m);
    for(int a = 0 ; a <= limit;a++){
        for(int b  = 0; b<= limit;b++){
            if(a*a+b == n && a + b*b ==m){
                ans++;
                break;
            }
        }
    }
    cout << ans;
}
