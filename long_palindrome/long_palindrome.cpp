#include<string>

 using namespace std;

class Solution {
public:
    string longestPalindrome(const string s) {
        if (s.empty()) {return "";}
        int maxLen = 1;
        int indice = 0;
        int len1 = 0;
        int len2 = 0;
        for (int i = 0; i < s.length(); i++) {
            len1 = expandAroundCenter(s, i, i);
            len2 = expandAroundCenter(s, i, i+1);
            int curMax = max(len1, len2);
            if (curMax > maxLen) {
                maxLen = curMax;
                indice = i;
            }
        } return s.substr(righpt, leftpt);
    }

public:
    int expandAroundCenter(const string& s,const int& i, const int& j){
        //reste a etendre en partant de i et j en verifiant a chauqe fois l egalite des chars
    }
};