#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007;

int main(){
    int n,m;
    cin >> n >> m ;
    int arr[n+1];
    for(int i = 1 ; i <= n; i ++ ) cin>>arr[i];
    
/*


casework on the first instance of the unkown element
so the array of n elements would have unkown elements let at say j1,j2,j3 .. indices respectively
number of ways which match the description only taking elements till x
dp[x] now we have to relate dp[x+1] with dp[x]
case 1 a[x] = 0 (* that means an unkown value) for any configuration


different train of thought

we should do casework on what the last element can be givn the constraints

dp x,y = total no of arrays satisfiying the given constraints taking uptill xth elements with the xth element being equal to y 

dp x,y = 0 if arr[x] > 0 and arr[x] != y
if arr[x] = 0 then our answer is going to be 

dp x,y = number of arrays till index x ending with y.
if y = arr[x] > 0 then if arr[x-1]>0 dp x,y = dp x-1,arr[x-1] if x = 1 then dp x,y = 1
                       if arr[x-1] = 0 then if y = M then dp x,y = dp x-1,y-1 + dp x-1,y
                                            if y = 0 then        = dp x-1,y+1 + dp x-1,y
                                            else          dp x,y = dp x-1,y-1 + dp x-1,y + dp x-1,y+1


dp x,y = if arr[x] > 0 and y != arr[x] then dp x,y = 0 else dp x,y  = dp x-1,y + (y=M ? 0 : dp x-1,y+1) + (y=0 ? dp x-1,y-1)
         if arr[x] = 0 then dp x,y  = dp x-1,y + (y=M ? 0 : dp x-1,y+1) + (y=1 ? 0 : dp x-1,y-1)
         dp 0,y = 0 for all y.
         our answer is going to be if arr[n] = 0 then dp[n][i] sum from i = 1 to M 
                                      if arr[n] > 0 then dp[n][arr[n]]
         for eg take n = 3 m = 5 arr = [2,0,2]
         if x = 1 and arr[x] = 0 then dp 1,y  = 1 for y from 1 to M   dp 1,0 = 0 


*/
    int* dp = new int[n+1];
    for (int i = 0; i <= m; i++) dp[i] = 0;
    if (arr[1]) dp[arr[1]] = 1;
    else {
        for(int i = 1 ; i<=m; i++) dp[i] = 1;
    }
    
    for(int i=2;i <= n;i++){
        int* temp = new int[m+1];
        for (int i = 0; i <= m; i++) temp[i] = 0;

       
        for(int j = 1; j <= m ; j++){
            if(arr[i]>0 && j!=arr[i]) temp[j]=0;
            else {
                temp[j] = dp[j];
                if (j>1) temp[j]+=dp[j-1]; temp[j]%=MOD;
                if (j<m) temp[j]+=dp[j+1]; temp[j]%=MOD;
            }
        }
        free(dp);
        dp = temp;   
    }
    /*
    n =3 m =5 [2,0,2]
    0 0 1 0 0 0 
    0 1 1 1 0 0 
    0 0 3 0 0 0 
    */
//    for(int i = 1 ; i<=m; i++) cout << dp[i] << " ";
//    cout << "\n";
    int ans=0;
    for(int i = 1 ; i<=m; i++) 
    {
        ans+=dp[i]; 
        ans%=MOD;
    }
    cout << ans << "\n";
    return 0;

}