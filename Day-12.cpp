class Solution {
public:
          bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        unordered_map<char, int> a,b;
        for (int i = 0; i < A.size(); i++) {
            a[A[i]]++;
            b[B[i]]++;
        }
        if (a != b) {
            return false;
        }
        int Count = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                Count++;
            }
            if (Count > 2) {
                return false;
            }
        }
        if (Count == 2) {
            return true;
        }
        else if(Count==0){
            if(!Check(a))
                return false;
            
            return true;
        }
           
        if (Count == 1) {
            return false;
        }
        return true;
    }
    
    bool Check(unordered_map<char, int> mp) {
        for (auto elem : mp) {
            if (elem.second > 1) {
                return true;
            }
        }
        return false;
    }
};