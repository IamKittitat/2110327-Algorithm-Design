#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void merge(vector<int> &v,int l,int m,int r,vector<int> &tmp){
    int bi = l;
    int ci = m+1;
    for(int i = l;i<=r;i++){
        if(ci > r){
            tmp[i] = v[bi++];
            continue;
        }
        if(bi > m){
            tmp[i] = v[ci++];
            continue;
        }
        tmp[i] = v[bi] > v[ci] ? v[ci++] : v[bi++];
    }
    for(int i = l;i<=r;i++) v[i] = tmp[i];
}

void merge_sort(vector<int> &v,int l,int r,vector<int> &tmp){
    if(l < r){
        int m = (l+r)/2;
        merge_sort(v,l,m,tmp);
        merge_sort(v,m+1,r,tmp);
        merge(v,l,m,r,tmp);
    }
}

int main()
{
    vector<int> v = {14,6392,124,19,-14,54,1,0,256,9,12,54,643,4,6,913,2,5,3123,54,331};
    vector<int> vtmp = v;
    sort(vtmp.begin(),vtmp.end());
    for(auto &x : vtmp) cout << x << " " ;
    cout << endl;
    vector<int> tmp(v.size());
    merge_sort(v,0,v.size()-1,tmp);
    for(auto &x : v) cout << x << " " ;
}
