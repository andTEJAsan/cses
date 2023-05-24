#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int MOD = 1000000007;
    cin >> n;
    int arr[7];
    for (int i = 0; i < 7; i++)
    {
        arr[i]=0;
    }
    arr[1]=1;
    
    int i =0;
    int dp = 1;
    for (int i = 1; i <= n; i++)
    {
        dp=arr[1];
        for (int i = 2; i < 7; i++)
        {
            dp+=arr[i];
            dp%=MOD;
        }
        
        for (int j = 6; j > 1; j--)
        {
            arr[j]=arr[j-1]%MOD;
        }
        arr[1]=dp;
        
    }
    cout << dp << "\n";    
    return 0;
}