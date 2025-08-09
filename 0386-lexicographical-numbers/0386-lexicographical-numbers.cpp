class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>result;
        for(int i =1;i<10;i++){
            dfs(i,n,result);
        }
        return result;
    }
private:
    void dfs(int curr,int n,vector<int>&result){
        if(curr>n) return;
        result.push_back(curr);
        for(int i=0;i<10;i++){
            int next =curr*10+i;
            if(next>n)return;
            dfs(next,n,result);
        }
    }
};