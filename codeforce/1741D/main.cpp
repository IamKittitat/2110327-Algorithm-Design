#include<iostream>
#include<vector>

using namespace std;

void merge(int start,int m, int stop,vector<int> &v,vector<int> &tmp,int &ans){
    if(stop-start == 1){
        if(v[stop] < v[start]){
            ans++;
            swap(v[start],v[stop]);
        }
        return;
    }

    if(v[m+1] < v[start]){
        ans++;
        int bi = start;
        int ci = m+1;
        for(int i=start;i<=m;i++) swap(v[bi++],v[ci++]);
    }

}

void ms(int start,int stop,vector<int> &v,vector<int> &tmp,int &ans){
    if(start < stop){
        int m = (start+stop)/2;
        ms(start,m,v,tmp,ans);
        ms(m+1,stop,v,tmp,ans);
        merge(start,m,stop,v,tmp,ans);
    }
}

int main(){
    int t;
    cin >> t;
    for(int i =0;i<t;i++){
        int m;
        cin >> m;
        vector<int> v(m),tmp(m);
        for(int j = 0;j<m;j++) cin >> v[j];
        int ans = 0;
        ms(0,v.size()-1,v,tmp,ans);
        bool beautiful = true;
        for(int j = 0;j<m-1;j++) if(v[j] > v[j+1]) beautiful = false;
        if(beautiful) cout << ans << endl;
        else cout << -1 << endl;
    }  
}