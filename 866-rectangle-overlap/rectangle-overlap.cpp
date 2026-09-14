class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x11 = rec1[0];
        int y11 = rec1[1];
        int x21 = rec1[2];
        int y21 = rec1[3];

        int x12 = rec2[0];
        int y12 = rec2[1];
        int x22 = rec2[2];
        int y22 = rec2[3];
        if (max(x11, x12) < min(x21, x22) && max(y11, y12) < min(y21, y22))
            return true;

        return false;
    }
}

;