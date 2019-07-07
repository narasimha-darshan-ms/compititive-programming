#include<iostream>

using namespace std;

int main(){
    
    int n,t;
    cin>>n>>t;
    int points[n], duration[n], dp[n][t + 1];
    
    for(int i = 0 ; i < n ; i++)    cin>>points[i];
        
    for(int i = 0 ; i < n ; i++)    cin>>duration[i];
        
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < t+1 ; j++)
            dp[i][j] = 0;
    
    for(int i = 0 ; i < t+1 ; i ++){     
        if( i == duration[0] )
            dp[0][i] = points[i];
        else dp[0][i] = 0;
    }
    
    for(int i = 1 ; i < n ; i ++)
        for(int j = 0 ; j < t+1 ; j++){
            if(j - duration[i] >= 0)
                dp[i][j] = max(dp[i-1][j] , dp[i - 1][ j - duration[i] ] + points[i]);
            else
                dp[i][j] = dp[i-1][j];
        }

    cout<<dp[n - 1][t];
    
    return 0;
}
