#include<bits/stdc++.h>
using namespace std;
int max_digit(int x){

    int number = x;
    int max_digit = -1 ;
    while(number > 0){
        max_digit = max(max_digit,number % 10);
        number /=10;
        if(max_digit == 9 ) break;
    }
    return max_digit;
}

int main(){
    int n;
    cin >> n;
    int previous_results[9];
    int ans_now = 0;
    for (int i = 0; i < 9; i++) previous_results[i] =0;
    for (int i = 1; i <= n; i++)
    {
        ans_now = 1 + previous_results[max_digit(i)-1];
        for(int j = 7; j >= 0 ; j--) previous_results[j+1]= previous_results[j];
        previous_results[0]=ans_now;
    }
    cout << previous_results[0];
    return 0;
}