class Solution {
public:
    struct Node {
        int maxLen;
        int pref;
        int suff;
        char leftChar;
        char rightChar;
    };
    vector<Node> segmentTree;
    Node mergeTree(const Node& left, const Node& right, int leftLen,
                   int rightLen) {

        int pref = left.pref;
        int suff = right.suff;
        if (pref == leftLen && left.rightChar == right.leftChar) {
            pref = leftLen + right.pref;
        }
        if (suff == rightLen && left.rightChar == right.leftChar) {
            suff = rightLen + left.suff;
        }
        Node res;
        res.pref = pref;
        res.suff = suff;
        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;
        int maxLen = max(left.maxLen, right.maxLen);

        if (left.rightChar == right.leftChar) {
            maxLen = max(maxLen, right.pref + left.suff);
        }
        res.maxLen = maxLen;
        return res;
    }

    void buildTree(int i, int l, int r, string &s) {
        if (l == r) {
            segmentTree[i] = {1, 1, 1, s[l], s[l]};
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(2 * i + 1, l, mid, s);
        buildTree(2 * i + 2, mid + 1, r, s);
        segmentTree[i] =
            mergeTree(segmentTree[2 * i + 1], segmentTree[2 * i + 2],
                      mid - l + 1, r - mid);
    }
    void update(int i, int l, int r, char s, int pos) {
        if (l == r) {
            segmentTree[i] = {1, 1, 1, s, s};
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(2 * i + 1, l, mid, s, pos);
        } else {
            update(2 * i + 2, mid + 1, r, s, pos);
        }

        segmentTree[i] =
            mergeTree(segmentTree[2 * i + 1], segmentTree[2 * i + 2],
                      mid - l + 1, r - mid);
    }
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        int n = s.length();
        segmentTree.assign(4 * n, Node());

        buildTree(0, 0, n - 1, s);
        int m = queryCharacters.length();
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            update(0, 0, n - 1, queryCharacters[i], queryIndices[i]);
            ans.push_back(segmentTree[0].maxLen);
        }
        return ans;
    }
};