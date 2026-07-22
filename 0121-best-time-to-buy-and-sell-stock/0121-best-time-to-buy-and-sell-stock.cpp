class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprices=prices[0];
        int maxprofit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]>minprices){
                maxprofit=max(prices[i]-minprices,maxprofit);
            }
            minprices=min(prices[i],minprices);
        }
        return maxprofit;
    }
};