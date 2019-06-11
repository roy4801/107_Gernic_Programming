#include <bits/stdc++.h>
using namespace std;
int ml[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string s;
int main(int argc, char *argv[])
{
    regex r("(0\\d|1[0-2])\\/(0\\d|1\\d|2\\d|3\\d)\\/(\\d{4})");
    while(cin >> s)
    {
        if(regex_match(s, r))
        {
            int m = stod(s.substr(0, 2));
            int d = stod(s.substr(3, 2));
            int y = stod(s.substr(6, 4));
            
            if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
                ml[2] = 29;
            else
                ml[2] = 28;
            if(d >= 1 && d <= ml[m])
            {
                printf("TRUE\n");
                continue;
            }
        }
        printf("FALSE\n");
    }
}