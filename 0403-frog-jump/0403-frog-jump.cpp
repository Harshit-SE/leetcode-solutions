class Solution {
public:
    unordered_map<int,int> mp;
    vector<vector<int>> dp;
    int n;

    bool solve(vector<int>& stones,int curri,int prev_jump){

        if(curri==n-1){
            return true;
        }

        if(dp[curri][prev_jump]!=-1)
            return dp[curri][prev_jump];

        bool result=false;

        for(int next_jump=prev_jump-1; next_jump<=prev_jump+1; next_jump++){

            if(next_jump<=0)
                continue;

            int next_stone=stones[curri]+next_jump;

            if(mp.find(next_stone)!=mp.end()){
                result = result || solve(stones, mp[next_stone], next_jump);
            }
        }

        return dp[curri][prev_jump]=result;
    }

    bool canCross(vector<int>& stones) {

        n=stones.size();

        if(n>1 && stones[1]!=1){
            return false;
        }

        dp.assign(n, vector<int>(n+1,-1));

        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }

        return solve(stones,0,0);
    }
};