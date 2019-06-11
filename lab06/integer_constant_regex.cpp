#include <bits/stdc++.h>
using namespace std;
// ref: https://www.oreilly.com/library/view/regular-expressions-cookbook/9781449327453/ch07s03.html
string s, fmt;
int main(int argc, char *argv[])
{
    regex r("^[+-]?([^0]\\d+|0[xX]([aAbBcCdDeEfF0-9])+|[0][0-7]*)([uUlLiI]|[uU]{2}|[lL])?$");
    regex print("^[+-]?(0[xX]([aAbBcCdDeEfF0-9])+|[0][0-7]*)([uUlLiI]|[uU]{2}|[lL])?$");
    while(cin >> s)
    {
        if(regex_match(s, r))
        {
            printf("TRUE");
            if(regex_match(s, print))
            {
                if(s.find("u") != string::npos || s.find("U") != string::npos)
                    fmt = move(" %d");
                else
                    fmt = move(" %+d");
                // hex
                if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
                    printf(fmt.c_str(), strtol(s.c_str(), NULL, 16));
                // octal
                else if(s[0] == '0' || ((s[0] == '+' || s[0] == '-') && s[1] == '0'))
                    printf(fmt.c_str(), strtol(s.c_str(), NULL, 8));
            }
            puts("");
        }
        else
            printf("FALSE\n");
    }
}