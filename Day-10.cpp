bool mycomp(const vector<int>&A,const vector<int>&B){
    return (A[1]<B[1]);
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
           
    if(points.size()==0) return 0;
    
    if(points.size()==1) return 1;
    
    
    sort(points.begin(),points.end(),mycomp);
    
    int count=1;
    int prev=points[0][1];
    
    for(int i=1;i<points.size();i++)
    {
        if(points[i][0]<=prev) 
        continue; 
        
        count++;
        prev=points[i][1];
    }
    
    
    return count;
    }
};