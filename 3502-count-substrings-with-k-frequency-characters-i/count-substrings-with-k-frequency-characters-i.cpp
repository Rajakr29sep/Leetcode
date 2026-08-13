class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int i =0;
        int j = 0;
        int n = s.length();
        if(k==1){
            return (n*(n+1))/2;
        }
        int ans = 0;
        unordered_map<int, int> mp;
        while (j < n) {
            mp[s[j] - 'a']++;
            while(i<j && mp[s[j]-'a']>=k){
                mp[s[i]-'a']--;
                i++;
            }
            ans+=i;
            j++;
        }

        return ans;
    }
};