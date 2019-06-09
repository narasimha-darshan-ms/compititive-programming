class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector< vector<int> > dependency(N);
        int possibleJudge = -1;
        
        for(int i = 0 ; i < trust.size() ; i++)
            dependency[trust[i][0] - 1].push_back(trust[i][1] - 1);
                                             
        
        for(int i = 0 ; i < N ; i++)    
            if(dependency[i].size() == 0){    possibleJudge = i + 1; break;      }
       
        if(possibleJudge == -1)    return -1;
      
        for(int i = 0 ; i < N ; i++){
            if(find(dependency[i].begin(), dependency[i].end(), possibleJudge - 1) == dependency[i].end() && possibleJudge != i +1)
                return -1;
        }
        return possibleJudge;
    }
};
