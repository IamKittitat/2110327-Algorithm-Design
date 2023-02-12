#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool solve(string &s1,string &s2,int l1,int r1,int l2,int r2){
    int len1 = r1-l1+1;
    int len2 = r2-l2+1;
    if(r1 == l1) return s1.substr(l1,len1) == s2.substr(l2,len2);

    int m1 = (l1+r1)/2;
    int m2 = (l2+r2)/2;
    bool firstCon = solve(s1,s2,l1,m1,l2,m2) && solve(s1,s2,m1+1,r1,m2+1,r2);
   
    bool secondCon = solve(s1,s2,l1,m1,m2+1,r2) && solve(s1,s2,m1+1,r1,l2,m2);
    if(firstCon) return true;
    if(secondCon) return true;

    return false;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s1,s2;
    cin >> s1 >> s2;
    if(solve(s1,s2,0,s1.size()-1,0,s2.size()-1)) cout << "YES";
    else cout << "NO";
}
