#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void shellSort(vector<int> &A){
    vector<size_t> gaps = {701,301,132,57,23,10,4,1};
    for(auto &g : gaps){
        cout << "GAPS " << g << endl;
        for(size_t i = g;i < A.size();i++){
            cout << "i " << i << endl;
            size_t tmp = A[i];
            size_t j;
            for( j = i;j>=g && A[j-g] > tmp;j-=g){
                cout<< j << " " << g << " | ";
                A[j] = A[j-g];
            }
            cout << endl;
            A[j] = tmp;
        }
    }
}

int main()
{
    vector<int> A = {1,9,3,6,7,8,2,6,1,4};
    for(auto &x : A) cout<< x << " ";
    cout << endl;
    shellSort(A);
    for(auto &x : A) cout<< x << " ";
}
