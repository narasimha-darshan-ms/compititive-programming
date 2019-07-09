class Solution {
public:
    string frequencySort(string a) {
        vector<pair<int,char>> map(128);
        string answer;
        for(int i = 0 ; i < 128 ; i++)   map[i].first = 0,map[i].second = i;
    
        for(int i = 0 ; i < a.length() ; i++){
            map[a[i]].first++;    
        }
    
        sort(map.begin() , map.end());

        for(int i = 127 ; i >= 0 ; i--){
            if(map[i].first == 0)   continue;
            int j = map[i].first;
            while(j > 0){   answer += map[i].second;  j--;      }
        }
        return answer;
    }
};
