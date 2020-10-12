class Solution {
public:
    string removeDuplicateLetters(string s) {
        bool seen[26];
        memset(seen,false,sizeof(seen));
        stack<int>st;
        int lastindex[26];
        for(int i=0;i<s.length();i++){
            lastindex[s[i]-'a']=i;
        }
         for(int i=0;i<s.length();i++){
             int c=s[i]-'a';
             if(seen[c]==true)
                 continue;
            
             while(!st.empty() && st.top()>(s[i]-'a') && i<lastindex[st.top()]){
                    seen[st.top()]=false;
                  st.pop();
             }
             
             st.push(s[i]-'a');
             seen[s[i]-'a']=true;
        }
        string res;
        while(!st.empty()){
            res += char(st.top()+'a') ;
            st.pop();
        }
       
        reverse(res.begin(), res.end());
         return res;
    }
};