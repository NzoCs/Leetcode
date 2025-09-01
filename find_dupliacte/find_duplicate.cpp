#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        for (const int& elem : nums) {
            int& nb = ++count[elem];
            if (nb > 1) {return true;}
        } return false;
    }
};