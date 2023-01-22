#include <bits/stdc++.h>

using namespace std;


int bsearch(vector<int> &v, int k,int start, int stop){
    if(start == stop) return v[start] == k ? start : -1;
    int m = (start+stop) >> 1;
    if(v[m] >= k) return bsearch(v,k,start,m);
    else return bsearch(v,k,m+1,stop);
}


/*
int bsearch(vector<int> &v, int k,int start, int stop){
    // cout << start << " " << stop << endl;
    if(start == stop) return v[start] == k ? start : -1;
    int m = (start+stop) >> 1;
    if(v[m] == k) return m;
    if(v[m] < k) return bsearch(v,k,m+1,stop);
    if(v[m] > k) return bsearch(v,k,start,m-1);
}
*/


int main()
{
    vector<int> v = {1,4,6,8,10,14,15,19,25,73};
    cout << bsearch(v,99,0,v.size()-1) << endl;
    for(auto &x : v) cout << bsearch(v,x,0,v.size()-1) << endl;

    cout << bsearch(v,-1,0,v.size()-1) << endl;
    cout << bsearch(v,7,0,v.size()-1) << endl;
    cout << bsearch(v,100,0,v.size()-1) << endl;
}
