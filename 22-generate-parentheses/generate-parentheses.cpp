class Solution {
    void solve(int n, int open, int close, vector<string>&ans, string s){
        if(s.length()==2*n){
            ans.push_back(s);
        }
        if(open<n){
            s+='(';
            solve(n,open+1,close,ans,s);
            s.pop_back();
        }
        if(close<open){
              s+=')';
            solve(n,open,close+1,ans,s);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        vector<string>ans;
        string s="";
        solve(n,open,close,ans,s);
        return ans;
    }
};