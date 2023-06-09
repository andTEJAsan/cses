#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    long long int x[n];
    for (int i = 0; i < n; i++) cin >> x[i];
    /*
    My thinking is that let f(i,j) be the optimal score possible then 
    f(i,j) = max(ai + (s(i+1,j) - f(i+1,j)) , aj + s(i,j-1) - f(i,j-1))
    ordering is based on k = j-i base case for i = j is that f(i,i) = ai
    we would need s(i,j) = sum(j) - sum(i-1) when i > 0
    s(i,j) = sum(j) when i = 0
    */ 
    long long int sum[n];
    sum[0] = x[0];
    for(int i = 1; i < n; i++) sum[i] = x[i] + sum[i-1];
    long long int f[n][n];
    for(int i = 0 ; i < n; i ++) f[i][i] = x[i];
    for(int k = 1 ; k < n; k ++ ){
        for(int i = 0; i < (n-k); i++){
            int j = i + k;
            f[i][j] = max(x[i] + (sum[j]-sum[i]-f[i+1][j]), x[j] + sum[j-1] - (i == 0 ? 0 : sum[i-1]) - f[i][j-1]);
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++) cout <<f[i][j]<< " ";
        cout << "\n";
    }
    return 0;
}