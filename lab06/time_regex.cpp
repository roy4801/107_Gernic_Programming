#include <bits/stdc++.h>
using namespace std;
string s;
int main(int argc, char *argv[])
{
    regex r("^(0\\d{1}|1\\d|2[0-3]):([0-5]{1}\\d{1}|60):([0-5]{1}\\d{1})$");
    while(cin >> s)
    {
        if(regex_match(s, r))
            printf("TRUE\n");
        else
            printf("FALSE\n");
    }
}