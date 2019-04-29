/*
There are n students standing in a row. Two coaches are forming two teams — the first coach chooses
the first team and the second coach chooses the second team.

The i-th student has integer programming skill ai. All programming skills are distinct and between 
1 and n, inclusive.

Firstly, the first coach will choose the student with maximum programming skill among all students
not taken into any team, and k closest students to the left of him and k closest students to the
right of him (if there are less than k students to the left or to the right, all of them will be 
chosen). All students that are chosen leave the row and join the first team. Secondly, the second
coach will make the same move (but all students chosen by him join the second team). Then again the
first coach will make such move, and so on. This repeats until the row becomes empty (i.e. the
process ends when each student becomes to some team).

Your problem is to determine which students will be taken into the first team and which students
will be taken into the second team.

Input:
The first line of the input contains two integers n and k (1≤k≤n≤2⋅105) — the number of students and
the value determining the range of chosen students during each move, respectively.

The second line of the input contains n integers a1,a2,…,an (1≤ai≤n), where ai is the programming
skill of the i-th student. It is guaranteed that all programming skills are distinct.

Output
Print a string of n characters; i-th character should be 1 if i-th student joins the first team,
or 2 otherwise.

Examples:

input
5 2
2 4 5 3 1
output
11111

input
5 1
2 1 3 5 4
output
22111

input
7 1
7 2 1 3 5 4 6
output
1121122

input
5 1
2 4 5 3 1
output
21112

Note:
In the first example the first coach chooses the student on a position 3, and the row becomes empty
(all students join the first team).

In the second example the first coach chooses the student on position 4, and the row becomes 
[2,1] (students with programming skills [3,4,5] join the first team). Then the second coach chooses
the student on position 1, and the row becomes empty (and students with programming skills [1,2] join
the second team).

In the third example the first coach chooses the student on position 1, and the row becomes
[1,3,5,4,6] (students with programming skills [2,7] join the first team). Then the second coach
chooses the student on position 5, and the row becomes [1,3,5] (students with programming 
skills [4,6] join the second team). Then the first coach chooses the student on position 3, 
and the row becomes [1] (students with programming skills [3,5] join the first team). And then the 
second coach chooses the remaining student (and the student with programming skill 1 joins the second
team).

In the fourth example the first coach chooses the student on position 3, and the row becomes
[2,1] (students with programming skills [3,4,5] join the first team). Then the second coach chooses
the student on position 1, and the row becomes empty (and students with programming skills [1,2] join
the second team).
*/

#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    int n,k,temp,max_index,aux_index,count = 0;
    cin>>n>>k;
    vector<int> arr;
    string answer; answer.resize(n);
    bool turnFlag = false, visited[n]; // false -> 1       true -> 2

    for(int i = 0 ; i < n ; i++){   cin>>temp; arr.push_back(temp); visited[i] = false;     }
   
    while( count < n ){
        max_index = max_element(arr.begin() , arr.end()) - arr.begin();
        visited[max_index] = true;
        arr[max_index] = -1;
        
        if( !turnFlag )answer[max_index] = '1';
        else{    answer[max_index] = '2';   }
        count++;
        aux_index = max_index - 1;
        int temp = 0;
        
        while( visited[aux_index] && aux_index > 0 ){    temp++; aux_index--;   }
        
        while(aux_index >= 0 && abs(aux_index - max_index) <= k + temp && count <= n ){  
            if( !turnFlag  && !visited[aux_index] )answer[aux_index] = '1';
            else if( !visited[aux_index] ){    answer[aux_index] = '2';   }
            visited[aux_index] = true;
            arr[aux_index] = -1 ;
            aux_index--;
            count++;
        }
        
        aux_index = max_index + 1;
        
        temp = 0;
        while( visited[aux_index] && aux_index > 0 ){    temp++; aux_index++;   }
        
        while(aux_index < n && abs(aux_index - max_index) <= k + temp && count <= n){  
            if( !turnFlag && !visited[aux_index] )answer[aux_index] = '1';
            else if(!visited[aux_index]){  answer[aux_index] = '2';    }
            visited[aux_index] = true;
            arr[aux_index] = -1;
            aux_index++;
            count++;
        }
        
        turnFlag = !turnFlag; 
    }
    cout<<answer;
    return 0;
}
