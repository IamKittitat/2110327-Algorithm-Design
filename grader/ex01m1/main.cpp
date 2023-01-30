#include<bits/stdc++.h>

using namespace std;
//int l,int x,int y,vector<pair<int,pair<int,int>> &v,int sX,int sY
void solve(int l,int x,int y,vector<pair<int,pair<int,int>>> &v,int sX,int sY){
    if(l == 2){
        // cout << "check " << l << " " << x << " " << y << " " << sX << " " << sY << endl;
        if(x == sX + 1 && y == sY + 1) v.push_back({3,{sX,sY}});
        else if(x == sX && y == sY + 1) v.push_back({2,{sX,sY}});
        else if(x == sX + 1 && y == sY) v.push_back({1,{sX,sY}});
        else if(x == sX && y == sY) v.push_back({0,{sX,sY}});
        else{
            //cout << "check " << l << " " << x << " " << y << " " << sX << " " << sY << endl;
        }
        return;
    }

    if(x < sX+l/2 && y < sY+l/2){ // missed in first Q
        //cout << "HI1 >> " << l << endl;
        solve(l/2,x,y,v,sX,sY); // Q1
        solve(l/2,sX+l/2,sY+l/2-1,v,sX+l/2,sY); // Q2
        solve(l/2,sX+l/2-1,sY+l/2,v,sX,sY+l/2); // Q3
        solve(l/2,sX+l/2,sY+l/2,v,sX+l/2,sY+l/2); // Q4
        v.push_back({0,{sX+l/2-1,sY+l/2-1}});
    } else if(x >= sX+l/2 && y < sY+l/2){ // missed in second Q
        //cout << "HI2 >>" << l << endl;
        solve(l/2,sX+l/2-1,sY+l/2-1,v,sX,sY); // Q1
        solve(l/2,x,y,v,sX+l/2,sY); // Q2
        solve(l/2,sX+l/2-1,sY+l/2,v,sX,sY+l/2); // Q3
        solve(l/2,sX+l/2,sY+l/2,v,sX+l/2,sY+l/2); // Q4
        v.push_back({1,{sX+l/2-1,sY+l/2-1}});
    } else if(x < sX+l/2 && y >= sY+l/2){ // missed in third Q
        //cout << "HI3 >> " << l << endl;
        solve(l/2,sX+l/2-1,sY+l/2-1,v,sX,sY); // Q1
        solve(l/2,sX+l/2,sY+l/2-1,v,sX+l/2,sY); // Q2
        solve(l/2,x,y,v,sX,sY+l/2); // Q3
        solve(l/2,sX+l/2,sY+l/2,v,sX+l/2,sY+l/2); // Q4
        v.push_back({2,{sX+l/2-1,sY+l/2-1}});
    } else{ // missed in fouth Q
        //cout << "HI4 >> " << l << " " << x << " " << y << " " << sX << " " << sY << endl;
        solve(l/2,sX+l/2-1,sY+l/2-1,v,sX,sY); // Q1
        solve(l/2,sX+l/2,sY+l/2-1,v,sX+l/2,sY); // Q2
        solve(l/2,sX+l/2-1,sY+l/2,v,sX,sY+l/2); // Q3
        //cout << "C" << endl;
        solve(l/2,x,y,v,sX+l/2,sY+l/2); // Q4
        v.push_back({3,{sX+l/2-1,sY+l/2-1}});
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int l,x,y;
    cin >> l >> x >> y;
    vector<pair<int,pair<int,int>>> v;
    solve(l,x,y,v,0,0);
    cout << v.size() << endl;
    for(auto &p : v){
        cout << p.first << " " << p.second.first << " " << p.second.second << "\n";
    }
}
