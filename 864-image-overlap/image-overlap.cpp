// company tags - google
class Solution {
    int countoverlap(vector<vector<int>>& A, vector<vector<int>>& B, int rowoff,
                     int coloff) {
        int n = A.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int B_i = i + rowoff;
                int B_j = j + coloff;
                if (B_i >= n || B_i < 0 || B_j < 0 || B_j >= n) {
                    continue;
                }
                if (A[i][j] == 1 && B[B_i][B_j]) {
                    count++;
                }
            }
        }
        return count;
    }

public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int maxoverlap = 0;
        for (int rowoff = -n + 1; rowoff < n; rowoff++) {
            for (int coloff = -n + 1; coloff < n; coloff++) {
                int count = countoverlap(A, B, rowoff, coloff);
                maxoverlap = max(count, maxoverlap);
            }
        }
        return maxoverlap;
    }
};