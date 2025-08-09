class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int i=0,j=0;
        while(j<trainers.size() && i<players.size()){
            if(players[i]<=trainers[j])i++;
            j++;
        }
        return i;
    }
};