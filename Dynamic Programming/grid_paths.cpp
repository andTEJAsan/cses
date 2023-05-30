#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007;
int main(){
    int n ;
    cin >> n ;
    int grid[n][n];
    
    for(int i=0;i<n;i++){ 
        for(int j = 0; j <n; j++){ 
            char x;
            cin >> x; 
            if (x =='.') grid[i][j]= 1;
            else grid[i][j]=0;
        }
    } 
    int paths[n][n];
    for(int sum = (2*n-2); sum >=0 ; sum--){
        int lowerbound= sum-n+1;
        int upperbound = n-1;
        if(sum < (n-1)){
            upperbound = sum;
            lowerbound = 0;
        }
        for (int x= lowerbound; x <= upperbound; x++)
        {
            int y = sum-x;
            int ans=0;
            if(grid[x][y]){
                if((x+1)<n) ans+=paths[x+1][y];
                if((y+1)<n ) ans+=paths[x][y+1];
                ans%=MOD;
                paths[x][y]=ans;
                if(sum==(2*n-2)) paths[x][y]=1;
            }
            else paths[x][y]=0;
        }
        
    }
    //for (int i = 0; i < n; i++)
    //{
    //    for(int k = 0; k < n ; k++) cout << paths[i][k] << " ";
    //    cout << "\n";
    //}
    cout << paths[0][0]<< "\n";
    return 0;

}