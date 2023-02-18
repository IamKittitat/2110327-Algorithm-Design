#include<iostream>
#include<vector>
#include<string>

using namespace std;

void solve(string &s1,string &s2,vector<vector<int>> &v){
    int len1 = s1.length()-1,len2 = s2.length()-1;
    string ans = "";
    int r = len1,c = len2;
    while(r > 0 && c > 0){
        if(s1[r] == s2[c]){
            ans = s1[r] + ans;
            r--; c--;
        }
        else{
            if(v[r-1][c] > v[r][c-1]){
                r--;
            } else{
                c--;
            }
        }
    }
    cout << ans;
}

int main(){
    int n,m;
    cin >> n >> m;
    string s1,s2;
    cin >> s1 >> s2;
    s1 = "x"+s1;
    s2 = "x"+s2;
    vector<vector<int>> v(n+1,vector<int>(m+1,0)); // n+1 * m+1  with all row is 0
    for(int i =0;i<=n;i++) for(int j=0;j<=m;j++) cin >> v[i][j];

    solve(s1,s2,v);
}