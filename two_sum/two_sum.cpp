#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;
        int firstIndice = 0;
        for (const int& elem : nums) {
            const int& complem = target - elem;
            const auto& it = lookup.find(complem);
            if (it != lookup.end()) {
                int secondIndice = it->second;
                vector<int> indices = {firstIndice, secondIndice};
                return indices;
            } lookup[elem] = firstIndice;
        } vector<int> null = {0};
        return null;
    }
};