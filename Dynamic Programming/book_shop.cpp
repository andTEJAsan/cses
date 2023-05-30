#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    int prices[n+1];
    int pages[n+1];
    for(int i = 1; i <= n; i++) cin>>prices[i];
    for(int i = 1; i <= n; i++) cin>>pages[i];
    int max_pages[x+1];
    // when no coin is being used then max_pages[i]= 0 for all i from 0 to x
    /*
    
    increment j from 0 to n , 0 meaning that no coin is used , n means that all coins have been used

    dp i,j = max( pages[j] + dp[i-prices[j]][j-1], dp[i][j-1])
    as both the branches reference the old value of dp for a particular amount in order to go to the next state in case we go from 0 to x, we would have lost the earlier value already which is why we go from x to 0 .

    
    */ 
    for(int i = 0 ; i <= x; i ++) max_pages[i]=0;
    for (int i = 1; i <= n; i++)
    {
        for (int amount = x; amount >= 0; amount--) // can't have the loop from 0 to x
        {
            int for_real = 0;
            if((amount-prices[i]) >= 0) {
                for_real = max_pages[amount-prices[i]];
            if ((pages[i]+for_real) > max_pages[amount]) max_pages[amount] = (pages[i]+for_real);
            }

        }
        
    }
    cout << max_pages[x] << "\n";
    return 0;

} 