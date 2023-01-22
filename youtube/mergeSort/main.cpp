#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &v,int start,int m,int stop,vector<int> &tmp){
    int bi = start;
    int ci = m+1;
    for(int i = start;i <= stop;i++){
        if(ci > stop) {tmp[i] = v[bi++]; continue;}
        if(bi > m) {tmp[i] = v[ci++]; continue;}
        tmp[i] = (v[bi] < v[ci]) ? v[bi++] : v[ci++];
    }
    for(int i = start;i <= stop;i++) v[i] = tmp[i];
}

void merge_sort(vector<int> &v ,int start,int stop,vector<int> &tmp){
    if(start < stop){
        int m = (start+stop) >> 1;
        merge_sort(v,start,m,tmp);
        merge_sort(v,m+1,stop,tmp);
        merge(v,start,m,stop,tmp);
    }
}


int main()
{
    vector<int> v = {14,6392,124,19,-14,54,1,0,256,9,12,54,643,4,6,913,2,5,3123,54,331};
    vector<int> tmp(v.size());
    merge_sort(v,0,v.size()-1,tmp);
    for(auto &x : v) cout << x << " " ;
}
