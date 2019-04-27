/*
This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

string S;
unordered_map<string,int> num;

int findNumWays(int index){
    if(index >= S.length()) return 1;
    if(index == S.length()-1){   
        num[S.substr(index)] = 1;
        return 1;
    } 
    else if(num[S.substr(index)] != 0)  return num[S.substr(index)]; 
    else{
        if(S.substr(index,index+1) <= "26"){
            if(num[S.substr(index)] == 0){
                num[S.substr(index)] = findNumWays(index + 1) + findNumWays(index + 2);
                return num[S.substr(index)];
            }      
            return num[S.substr(index)];
    } 
    else{
        if(num[S.substr(index)] == 0){
                num[S.substr(index)] = findNumWays(index + 1);
                return num[S.substr(index)];
            }      
        return num[S.substr(index)];
        }
    }
    return 0;
}

int main() {
    cin>>S;
    if(S.find('0') != string::npos){  
        cout<<"0";
        return 0;
    }
    
    cout<<findNumWays(0); 
	
	return 0;
}
