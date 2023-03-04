#include <bits/stdc++.h>

using namespace std;

/*
u v
w p
*/
long long u,v,w,p;

long long solve(long long len,long long sx,long long sy,long long r,long long c){
    // cout <<"CHECK " <<  len << endl;
    if(len == 2){
        // scout << r-sy << " " << c-sx << endl;
        if(r-sy==0 && c-sx==0) return u;
        if(r-sy==0 && c-sx==1) return v;
        if(r-sy==1 && c-sx==0) return w;
        if(r-sy==1 && c-sx==1) return p;
    }

    long long mx = sx+len/2,my = sy+len/2;
    if(r < len/2 && c < len/2){
        return solve(len/2,sx,sy,r,c);
    }
    if(r >= len/2 && c < len/2){
        return -solve(len/2,sx,sy,r-len/2,c);
        //return -solve(len/2,mx,sy,r,c-len/2);
    }

    if(r < len/2 && c >= len/2){
        return solve(len/2,sx,sy,c-len/2,r);
    }
    if(r >= len/2 && c >= len/2){
        return -solve(len/2,sx,sy,c-len/2,r-len/2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n,m;
    cin >> n >> m;
    long long len = 1LL << n;
    cin >> u >> v >> w >> p;
    for(int i =0;i<m;i++){
        long long r,c;
        cin >> r >> c;
        cout << solve(len,0,0,r-1,c-1) << "\n";
    }

}


/*
3 4
1 2 3 4
1 1
2 4
4 3
4 4

*/