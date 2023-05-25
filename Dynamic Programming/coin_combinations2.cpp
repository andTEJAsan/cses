#include<iostream>
using namespace std;
#define nl "\n";
#define MOD 1000000007;
int main(){
    int n,x;
    cin>>n>>x;
    int c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    /* what is the subquestion that I need to ask ? 
    I need to find the distinct unordered ways of partitioning an amount x given the denominations which are c[0] .. c[n-1]
    ok 
    any solution is fully chracterised by the number of occurences of ith coin in it 
    Let dp x,y = no of ways of partitioning the sum x with the maximum occurence being y times
    dp x,y --> either 0 or 1 or 2 or ... n-1 is going to be the maximum
    if ith coing is the maximum then the number of such unordered ways is dp 
    then our answer is going to be sum over y going from 0 to x/min(c[i])
    -------------------------

    different train of thought

    dp x,y = no of ways of partitioning the sum x with the maximum occurence being at max y, it could be less than y
    either 0 or 1 or 2 or ... n-1 th coing is going to occur the maximum number of times


-------------------------------------------

    different train of thought



    dp x,y = no of ways of partitioning the sum x with the yth coing having the maximum occurence
    if yth coing has the maximum  then that maximum occurence could be anything from 1 to k where k is the greatest 
    integer such that x-k*c[y] >=0  -->   k <= x/c[y] so the max k= ceil(x/c[y])
    this clearly wont work because if I move to a smaller amount, I can't gaurantee that the same choice of coin wouldnt be used for the maximum again

------------------------------------------


    different train of thought

    dp x,y = no of ways of partitioning the sun x with the coins upto y 

    this might work , because if we recurse on a smaller y we wont repeat our choice of coin
    ok so either the yth coin is chosen 0 times at max k = ceil (x/c[y]) so for the ith times it is repeated then 
    the number of ways is going to be dp x-k*c[y], y-1 and we can write dp now as

    dp x,y = sum over {ceil(x/c[y])} of i | dp x-i*c[y], y-1
    treat y as a state variable


this works !! but got a horrible time complexity
optimize it like this 
    dp x-c[y],y
    dp x,y = dp x,y-1 + dp x-c[y],y
    dp[x]+=dp[x-c[y]]
    treat y as the state which captures at max which numbered coin we can use in our solutions
    initially only the 0th coin can we take, we grow the coins inductively
    */
    int dp[x+1];
    dp[0]=1;
    for (int i = 0; i < x; i++)
    {
        dp[i+1]=0;
    }
    for (int i = 0; i < n; i++)
    {
       
        for (int j = 1; j < (x+1); j++)
        {
            if ( j >= c[i] ) dp[j]+=dp[j-c[i]];
            dp[j]%=MOD;
        }
        
    }
    cout << dp[x];
   
    //for (int i = 0; i < (x+1); i++)
    //{
    //    for (int j = 0; j < n; j++)
    //    {
    //       cout << dp[i][j] << " ";
    //    }
    //cout << nl;
    //}
    return 0;
}