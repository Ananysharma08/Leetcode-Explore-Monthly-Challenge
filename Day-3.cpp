class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto z:nums){
            m[z]++;
        }
        int count=0;
        if(k==0){
            for(auto x: m){
                if(x.second>1)
                    count++;
            }
            return count;
        }
        
        for(auto x:m){
            if( m.find(x.first-k)!=m.end())
                count++;
        }
        return count;
    }
};