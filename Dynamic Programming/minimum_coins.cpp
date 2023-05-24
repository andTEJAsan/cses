#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin >>n>> x;
    int c[n];
    for (int i = 0; i < n; i++)
    {
        cin>>c[i];
    }
    int dp[x+1];
    for (int j= 0; j <= x; j++)
    {
    dp[j]=-1;
    }
    dp[0]=0;
    for (int i = 1; i <= x; i++)
    {
        for(int j = 0 ;  j < n ; j++){
            if( i< c[j] || dp[i-c[j]]== -1) continue;
            if((1+dp[i-c[j]]) < dp[i] || (dp[i] == -1)) dp[i] = (1+dp[i-c[j]]);
        }
    }
 cout << dp[x];  

    return 0;
}