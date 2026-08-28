class Solution {
public:
typedef long long ll;
    bool isPossible(vector<int>& ranks, ll mid ,int cars){
        ll carfixed=0;
        for(int i=0;i<ranks.size();i++){
            carfixed+=sqrt(mid/ranks[i]);
        }
        return carfixed>=cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        ll left=1;
        ll maxr=*max_element(ranks.begin(),ranks.end());
        ll right=maxr*cars*cars;
        ll result=-1;
        while(left<=right){
            ll mid=left+((right-left)/2);
            if(isPossible(ranks,mid,cars)){
               result=mid;
               right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return result;
    }
};