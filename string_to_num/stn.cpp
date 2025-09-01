#include <cctype>
#include <string>
#include <climits> // INT_MAX, INT_MIN

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // Ignorer espaces initiaux
        while (i < n && s[i] == ' ') i++;

        // Gérer signe
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        long long result = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Vérification overflow anticipée
            if (result > (LLONG_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        result *= sign;

        // Clamp final au cas où
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return static_cast<int>(result);
    }
};
