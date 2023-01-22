#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
    setIO("pails");
    int x,y,m,ans = -1;
    cin >> x >> y >> m;
    for(int i = 0; i <= m;i++){
        if(x*i > m) break;
        for(int j = 0; j <= m;j++){
            int now = x*i + y*j;
            if(now > m) break;
            ans = max(ans,now);
        }
    }
    cout << ans;
}
