#include <bits/stdc++.h>

using namespace std;

int ans = 0;
void merge(int start,int m,int stop,vector<int> &v,vector<int> &tmp){
    int b = start, c = m+1;
    for(int i = start;i<=stop;i++){
        if(c > stop)tmp[i] = v[b++];
        else if(b > m) tmp[i] = v[c++];
        else{
            if(v[b] > v[c]){
                // cout << v[b] << " " << v[c] <<" " <<m << " " <<  b << " " << c << endl;
                ans += m-b+1;
                tmp[i] = v[c++];
            } else{
                tmp[i] = v[b++];
            }
        }
    }
    for(int i = start;i<=stop;i++) v[i] = tmp[i];
}

void merge_sort(int start,int stop,vector<int> &v,vector<int> &tmp){
    if(start < stop){
        int m = (start+stop)/2;
        merge_sort(start,m,v,tmp);
        merge_sort(m+1,stop,v,tmp);
        merge(start,m,stop,v,tmp);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n),tmp(n);
    for(int i=0;i<n;i++) cin >> v[i];
    merge_sort(0,v.size()-1,v,tmp);
    cout << ans;
}
