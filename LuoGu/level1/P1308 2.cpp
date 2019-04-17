#include <iostream>
#include <string.h>
#include <sstream>
 
using namespace std;
 
string transform(const std::string str)
{
    string transformstr;
    char *value = new char[1];
    for (size_t i = 0; i < str.size(); i++)
    {
        strcpy(value, str.substr(i, 1).c_str());
        transformstr += toupper(*value);
    }
 
    return transformstr;
}
 
int main()
{
    string first, second, third = "", middle;
    char c;
    int sum = 0, pos;
    bool firstpos = true;
    cin >> first;
 
    cin.get();
    while ((c = cin.get()) != '\n')
        second += c;
 
    first = transform(first);
    second = transform(second);
 
    unsigned int stringsize = second.size();
    for (size_t i = 0; i < stringsize; i++)
    {
        while (i<stringsize && (middle = second.substr(i, 1)) != " ")
        {
            third += middle;
            i++;
        }
                
        if (first == third)
        {
            sum++;
            if (firstpos)
            {
                pos = i - third.size();
                firstpos = false;
            }
        }
            
        third = "";
    }
 
    if (sum != 0)
        cout << sum << " " << pos << endl;
    else
    {
        sum = -1;
        cout << sum  << endl;
    }
    //system("pause");
    return 0;
}
