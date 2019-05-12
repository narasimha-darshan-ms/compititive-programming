#include<iostream>

using namespace std;

int main(){
    string str;
    int n, count = 0;
    cin>>n>>str;
    
    for(int i = 0 ; i < n ; i++){
        while(count == 0 && i < n && str[i] == '-')     i++;
        if(count != 0 && str[i] == '-')     count--;
        if(str[i] == '+')   count++;
        
    }
    cout<<count;
    return 0;
}
