#include <bits/stdc++.h>

using namespace std;

void recur(vector<vector<int>> &v,int a, int b,int x,int y,int s){
    // cout << x << " " << y << " " << s << endl;
    if(a == 0){
        v[y][x] = b;
        return;
    }
    recur(v,a-1,b,x,y,s/2);
    recur(v,a-1,b-1,x+s/2,y,s/2);
    recur(v,a-1,b+1,x,y+s/2,s/2);
    recur(v,a-1,b,x+s/2,y+s/2,s/2);
}

int main()
{
     ios_base::sync_with_stdio(false); cin.tie(0);
     int a,b;
     cin >> a >> b;
     vector<vector<int>> v(1<<a,vector<int>(1<<a));
     recur(v,a,b,0,0,1<<a);
     for(int i = 0;i< v.size();i++){
        for(int j = 0;j< v[i].size();j++) cout << v[i][j] << " " ;
        cout << "\n";
     }
}
