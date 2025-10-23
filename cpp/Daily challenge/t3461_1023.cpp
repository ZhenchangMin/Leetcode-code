#include <string>
using namespace std;
class Solution
{
public:
    string execute(string &s)
    {
        while (s.length() > 2)
        {
            string ans;
            int tmp = 0;
            for (int i = 0; i < s.length() - 1; i++)
            {
                tmp = (s[i] - '0') + (s[i + 1] - '0');
                tmp %= 10;
                ans.append(to_string(tmp));
            }
            s = ans;
        }
        return s;
    }
    bool hasSameDigits(string s)
    {
        execute(s);
        return s[0] == s[1];
    }
};