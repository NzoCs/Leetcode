#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int rPt = height.size();
        int lPt = 0;
        int rBest = rPt;
        int lBest = lPt;
        int maxArea = 0;
        while (lPt < rPt) {
            int curArea = (rPt - lPt) * min(height[rPt], height[lPt]);
            if (curArea > maxArea) {maxArea = curArea;}
            if (height[rPt]>height[lPt]) {lPt++;}
            else {rPt++;}
        } return maxArea;
    }
};