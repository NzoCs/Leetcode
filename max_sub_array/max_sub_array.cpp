#include<vector>
#include<climits>
#include<array>
#include<algorithm>
#include<iostream>

using namespace std;

//sol 1 O(N) Dynamic Programming
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        
        int bestEnd = INT_MIN;
        int best = INT_MIN;
        const int size = nums.size();

        for (int i = 0; i<size; i++) {

            if (bestEnd >= 0){bestEnd += nums[i];} 
            else {bestEnd = nums[i];} 
            
            if (bestEnd > best) {best = bestEnd;}

        } 
        
        return best;
    }
};

//sol 2 O(N) Divide and conquer, moins efficace car code généré en asm plus compliqué (récursion et
class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        array<int, 4> result = dandc(nums, left, right);
        const int& best = result[0];
        return best;
    }

array<int, 4> dandc(const vector<int>& nums, int left, int right) {

    if (left == right) {
        int val = nums[left];
        return {val, val, val, val};
    } 
    
    int mid = (left + right)/2;

    array<int, 4> resultL = dandc(nums, left, mid);
    array<int, 4> resultR = dandc(nums, mid + 1, right);

    const int& bestL = resultL[0], bestStartL = resultL[1], bestEndL = resultL[2], totalSumL = resultL[3];

    const int& bestR = resultR[0], bestStartR = resultR[1], bestEndR = resultR[2], totalSumR = resultR[3];

    int totalSum = totalSumL + totalSumR;

    int best = max({bestStartR + bestEndL, bestL, bestR});
    cout << best << endl;
    
    int bestStart;
    if (bestL == totalSumL && bestStartR > 0) {
        bestStart = bestStartL + bestStartR;
    } else {bestStart = bestStartL;}

    int bestEnd;
    if (bestR == totalSumR && bestEndL > 0) {
        bestEnd = bestEndR + bestEndL;
    } else {bestEnd = bestEndL;}

    return {best, bestStart, bestEnd, totalSum};
}
};