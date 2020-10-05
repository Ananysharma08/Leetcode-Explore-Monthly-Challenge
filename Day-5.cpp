class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0)
            return 1;
        int n=N;
        int count=0;
        while(n){
            count++;
            n=n>>1;
        }
        return pow(2,count)-1-N;
    }
};