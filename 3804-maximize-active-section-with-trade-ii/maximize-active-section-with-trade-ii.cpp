void buildSegmentTree(int i, int l, int r, int segmentTree[], int arr[]) {
    if (l == r) {
        segmentTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
    buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
    segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
}

int* constructST(int arr[], int n) {
    int* segmentTree = new int[4 * n];
    buildSegmentTree(0, 0, n - 1, segmentTree, arr);
    return segmentTree;
}

int querySegmentTree(int start, int end, int i, int l, int r,
                     int segmentTree[]) {
      if (l > end || r < start) {
        return INT_MIN;
    }

    if (l >= start && r <= end) {
        return segmentTree[i];
    }

    int mid = l + (r - l) / 2;
    return max(
        querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree),
        querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree));
}

int RMQ(int st[], int n, int a, int b) {
    return querySegmentTree(a, b, 0, 0, n - 1, st);
}

class Solution{
public:
   vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        vector<int> blockStart;
        vector<int> blockEnd;
        int activeOne = count(begin(s), end(s), '1');
        int i = 0;
        int n= s.length();
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0')
                    i++;
                blockStart.push_back(start);
                blockEnd.push_back(i - 1);
            } else {
                i++;
            }
        }
        if (blockStart.size() < 2) {
            return vector<int>(queries.size(), activeOne);
        }
        int N = blockStart.size();
        vector<int> blockSize(N);
        for (int i = 0; i < N; i++) {
            blockSize[i] = blockEnd[i] - blockStart[i] + 1;
        }

        int k = N - 1;
        vector<int> pairSum(k);
        for (int i = 0; i < k; i++) {
            pairSum[i] = blockSize[i] + blockSize[i + 1];
        }

        int* st = constructST(pairSum.data(), k);
        int m = queries.size();
        vector<int> ans;

        for(auto &q : queries) { //O(q*log)
            int l = q[0];
            int r = q[1];

            //first block in this range
            int low  = lower_bound(begin(blockEnd), end(blockEnd), l) - begin(blockEnd); //log
            int high = upper_bound(begin(blockStart), end(blockStart), r) - begin(blockStart) - 1; //log

            int maxPairSum = 0;
            if(low < high) { //we need atleast two blocks
                int firstLen = blockEnd[low] - max(blockStart[low], l) + 1; 
                int lastLen  = min(blockEnd[high], r) - blockStart[high] + 1;

                if(high - low == 1) { //exactly two blocks are there only
                    maxPairSum = firstLen + lastLen;
                } else {
                    int pair1 = firstLen + blockSize[low+1];
                    int pair2 = blockSize[high-1] + lastLen;
                    int RMQMaxPairSum = RMQ(st, k, low+1, high-2); //log
                    maxPairSum = max({pair1, pair2, RMQMaxPairSum});
                }
            }
            ans.push_back(maxPairSum + activeOne);
        }
        return ans;
    }
};