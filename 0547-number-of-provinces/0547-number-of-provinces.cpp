class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count=0;
        vector<bool>isVisited(n,false);
        for(int i = 0;i<n;i++){
            if(!isVisited[i]){
                bfs(i,isVisited,isConnected);
                count++;
            }
        }
        return count;
    }
private:
    void bfs(int start,vector<bool>&isVisited,vector<vector<int>>isConnected){
        queue<int>q;
        q.push(start);
        isVisited[start]=true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0;i<isConnected.size();i++){
                if(!isVisited[i] && isConnected[node][i]){
                    isVisited[i]=true;
                    q.push(i);
                }
            }
        }
    }
};
