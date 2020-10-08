class Solution {
public:
    int solve(vector<int>&nums, int low, int hi,int target){
        if(low<=hi){
        int mid=(low+hi)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]<target){
            return solve(nums,mid+1,hi,target);
        }
        else
            return solve(nums,low,mid-1,target);
    }
      return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int x=solve(nums,0,nums.size(),target);
        return x;
    }
};