#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main() {

    int n,x;
    cin >> n >> x;
    int c[n];

    for (int i = 0; i <n; i++)
    {
        cin >> c[i];
    }

    int dp[x+1];
    dp[0]=1;
    for (int i = 1; i <= x; i++)
    {
        int sum=0;
        for (int j = 0; j < n; j++)
        {
            if( i < c[j] ) continue;
            sum+=dp[i-c[j]];
            sum%=MOD;
        }
        dp[i]=sum;
    }
    cout << dp[x];    
    return 0;
}