/*
String Rotation:

Problem Description
Rotate a given String in specified direction by specified magnitude.

After each rotation make a note of first character of the rotated String, After all rotation are performed the accumulated first
character as noted previously will form another string, say FIRSTCHARSTRING.

Check If FIRSTCHARSTRING is an Anagram of any substring of the Original string.

If yes print "YES" otherwise "NO".

Constraints
1 <= Length of original string <= 30

1<= q <= 10

Input Format
The first line contains the original string s. The second line contains a single integer q. The ith of the next q lines contains 
character d[i] denoting direction and integer r[i] denoting the magnitude.

Output
YES or NO

Test Case

Explanation
Example 1

Input

carrace 3 L 2 R 2 L 3

Output

NO

Explanation After applying all the rotations the FIRSTCHARSTRING string will be "rcr" which is not anagram of any sub string of original
string "carrace".
*/

#include<iostream>

using namespace std;

bool checkArray(int *a , int *b ){
    for(int i = 0 ; i < 26 ; i++)
        if(a[i] != b[i])    return false;
    return true;
}

int main(){
	string text,result;
  	int q,n;
    cin>>text>>q;
    int r[q]; char d[q];
    
    n = text.length();
    
    for(int i = 0 ; i < q ; i++){   cin>>d[i]>>r[i];    }
    
    for(int i = 0 ; i < q ; i++){   
        string temp;
        if(d[i] == 'L'){
            temp =  text.substr(0 , r[i] );
            text.erase(0 , r[i]);
            text = text + temp;
            result += text[0]; 
        }
        else if(d[i] == 'R'){
            temp =  text.substr(n - r[i] , n-1);
            text.erase(n - r[i] , n-1);
            text = temp + text;
            result += text[0];
        }   
        
    }  
    
    int alpha[26], checkAlpha[26];
    for(int j = 0 ; j < q ; j++ )   alpha[result[j] - 'a']++ , checkAlpha[text[j] - 'a']++ ;
    if( checkArray(alpha , checkAlpha ) ){   cout<<"YES"; return 0;  }
    
    for(int i = 1 ; i < n - q  ; i++){
        checkAlpha[text[i - 1] - 'a']--;
        checkAlpha[text[i + q -1] - 'a']++;
        if( checkArray(alpha , checkAlpha) ){   
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
  	return 0;
}
