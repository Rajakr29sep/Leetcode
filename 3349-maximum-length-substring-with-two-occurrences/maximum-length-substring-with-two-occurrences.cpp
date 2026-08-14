class Solution {
public:
    int maximumLengthSubstring(string s) {
       int i =0;
        int j  = 0;
        int n = s.length();
        unordered_map<int,int>mp;
        int ans = 0;
        while(j<n){
            mp[s[j]-'a']++;
            while(i<j && mp[s[j]-'a']>2){
                mp[s[i]-'a']--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        } 

        return ans;
    }
};