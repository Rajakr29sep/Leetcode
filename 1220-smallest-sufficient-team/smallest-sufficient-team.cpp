class Solution {
public:
//approximately solved by me took help from ai 

    vector<int> solve(vector<int>& personMask, int i, int mask, int target,
                      vector<vector<vector<int>>>& dp) {
        // All skills covered
        if (mask == target) {
            return {};
        }

        // No more people
        if (i == personMask.size()) {
            return {-1};
        }

        // Already calculated
        if (!dp[i][mask].empty()) {
            return dp[i][mask];
        }

        // Don't pick current person
        vector<int> notPick = solve(personMask, i + 1, mask, target, dp);

        // Pick current person
        int newMask = mask | personMask[i];

        vector<int> pick = solve(personMask, i + 1, newMask, target, dp);

        if (pick.size() != 1 || pick[0] != -1) {
            pick.push_back(i);
        } else {
            pick = {-1};
        }

        // Choose smaller valid team
        if (notPick.size() == 1 && notPick[0] == -1) {
            return dp[i][mask] = pick;
        }

        if (pick.size() == 1 && pick[0] == -1) {
            return dp[i][mask] = notPick;
        }

        return dp[i][mask] = (pick.size() < notPick.size()) ? pick : notPick;
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                       vector<vector<string>>& people) {
        int n = req_skills.size();
        int target = (1 << n) - 1;

        // skill -> bit
        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {
            mp[req_skills[i]] = i;
        }

        // Convert every person's skills into a bitmask
        vector<int> personMask(people.size(), 0);

        for (int i = 0; i < people.size(); i++) {
            for (string& skill : people[i]) {
                if (mp.count(skill)) {
                    personMask[i] |= (1 << mp[skill]);
                }
            }
        }

        // dp[i][mask] = minimum team from i onward
        // that can complete 'mask'
        vector<vector<vector<int>>> dp(people.size(),
                                       vector<vector<int>>(target + 1));

        return solve(personMask, 0, 0, target, dp);
    }
};