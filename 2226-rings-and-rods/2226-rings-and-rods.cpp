class Solution {
public:
    int countPoints(string rings) {
        vector<vector<int>> rods(10,vector<int>(3,0));
        int n = rings.size();
        for(int i = 0; i<n; i += 2){
            if(rings[i] == 'R'){
                rods[rings[i+1]-'0'][0] = 1;
            }else if(rings[i] == 'G'){
                rods[rings[i+1]-'0'][1] = 1;
            }else if(rings[i] == 'B'){
                rods[rings[i+1]-'0'][2] = 1;
            }
        }

        int ans = 0;
        for(int i = 0; i<10; i++){
            if(rods[i][0] == 1 && rods[i][1] == 1 && rods[i][2] == 1)
            ans++;
        }
        return ans;
    }
};