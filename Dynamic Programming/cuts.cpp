#include<bits/stdc++.h>
using namespace std;
int f(int i , int j){
    if (i==j) return 0;
    else if (i > j) return (f(j,i));
    else if (j % i ==0) return j/i -1;
    else return (j/i+f(j%i,i) );
}

int main () {

    int n;
    cin >> n;
    int coins[n+1];
    for(int i = 0 ; i < n; i++) cin >> coins[i+1];
    int* amounts = new int[100001];
    for(int i = 1 ; i <= 100000; i++) amounts[i]=0;
    amounts[0]=1;
    for(int i = 1 ; i<= 100000; i++){
    for(int j = 1; j <=n; j ++){
       if(i-coins[j] >=0) amounts[i] = (amounts[i] | amounts[i-coins[j]]);
         }
    }
    int sum = 0;
    for(int i =1 ; i <= 100000; i++) sum+=amounts[i];
    cout << sum << "\n";
    for(int i =1 ; i <= 100000; i++) cout << i << " ";

    
}