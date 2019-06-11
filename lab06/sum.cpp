#include <bits/stdc++.h>
using namespace std;

string s, fmt;
vector<int> v;
regex r("([+-]?(?:([1-9][0-9]*)|(0[0-7]*)|0x([0-9A-F]+)|0b([01]+))[lLuUiI]?)\\b");
smatch sm;
bool fl;
int main(int argc, char *argv[])
{
    v.reserve(16);
    while(getline(cin, s))
    {
        if(fl) puts("");
        v.clear();
        while(regex_search(s, sm, r))
        {
            auto cur = sm[0].str();
            if(cur.substr(0,2) == "00")
                v.push_back(strtol(cur.c_str(), NULL, 8));
            else
                v.push_back(stod(cur));
            s = sm.suffix().str();
        }
        sort(v.begin(), v.end(), greater<int>());
        for(int i : v)
            cout << i << (i==v.back()?'\n':' ');
        cout << accumulate(v.begin(), v.end(), 0) << '\n';
        fl = true;
    }
}
