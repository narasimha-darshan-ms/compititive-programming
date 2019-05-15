class Solution {
public:
    bool buddyStrings(string A, string B) {
        if((A.size() == 0 && B.size() != 0) || (A.size() != 0 && B.size() == 0))
            return false;
        if(A.size() != B.size())    return false;
        if(A == B){
            sort(A.begin() , A.end());
            for(int i = 1 ; i < A.size() ; i++)
                if(A[i] == A[i-1])  return true;
            return false;
        }
        int count = 0, pos[3] ={0};
        for(int i = 0, j = 0 ; i < A.size() ; i++){
            if(A[i] != B[i] && count <= 2)  count++, pos[j++] = i;
            if(count == 3)  return false;
        }
        if(A[pos[1]] == B[pos[0]] && B[pos[1]] == A[pos[0]])    return true;
        else    return false;
    }
};
