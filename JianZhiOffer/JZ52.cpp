#include <string>
using namespace std;

bool match(string str, string pattern) {
    auto pstr = str.begin();
    auto ppat = pattern.begin();
    while (pstr != str.end())
    {
        auto next = *(ppat + 1);
        switch (next)
        {
        case '+':
        {
            bool once = false;
            while (*pstr == *ppat)
            {
                once = true;
                ++pstr;
            }
            if (!once) return false;
            ++ppat;
            break;
        }
        case '*':
            while (*pstr == *ppat) ++pstr;
            ++ppat;
            break;
        default:
            if (*pstr == *ppat) ++pstr;
            else return false;
            break;
        }
        ++ppat;
    }
    return true;
}

int main()
{
    match("aaa", "a+a");
}