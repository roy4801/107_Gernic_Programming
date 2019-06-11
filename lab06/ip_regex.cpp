#include <bits/stdc++.h>
using namespace std;

string s;
int main(int argc, char *argv[])
{
    regex r("^((2[0-4]\\d|25[0-5]|1[0-9]{2}|\\d{1,2})\\.){3}(2[0-4]\\d|25[0-5]|1[0-9]{2}|\\d{1,2})$");
    while(cin >> s)
    {
        if(regex_match(s, r))
            printf("TRUE\n");
        else
            printf("FALSE\n");
    }
}