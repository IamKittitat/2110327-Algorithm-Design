#include<iostream>
#include<vector>
#include<set>

using namespace std;

/** Two pointer approach with O(n**2) PPPPPPPPPP **/
bool twoPointer(int idx,int q,vector<int> &v){
    int l = 0,r=v.size()-1;
    while(l<r){
        int sum = v[l]+v[r];
        if(sum == q) return true;
        else if(sum < q){
            l++;
            if(l == idx) l++;
        } else{
            r--;
            if(r == idx) r--;
        }
    }
    return false;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<m;i++){
        int q;
        cin >> q;
        bool found = false;
        for(int j = 1;j<n-1;j++){
            if(twoPointer(j,q-v[j],v)){
                found = true;
                break;
            }
        }
        if(found) cout << "YES\n";
        else cout << "NO\n";
    }   
}


/** O(n**2lgn) with PPPPPTTTTT **/
/*bool pairSum(vector<int> &v,int q,set<int> &s,int fi){
    auto it1 = s.find(v[fi]);
    for(int i = 0;i<v.size();i++){
        auto it2 = s.find(v[i]);
        auto it3 = s.find(q-v[i]);
        if(it3 != s.end() && (it1 != it2 && it1 != it3 && it2 != it3)) return true;
    }
    return false;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    set<int> s;
    for(int i=0;i<n;i++){
        cin >> v[i];
        s.insert(v[i]);
    }
    for(int j=0;j<m;j++){
        int q;
        cin >> q;
        bool found = false;
        for(int k = 0;k<n;k++){
            if(pairSum(v,q-v[k],s,k)) found = true;
        }
        if(found) cout << "YES\n";
        else cout << "NO\n";
    }
}*/