#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <ctime>

#define PB push_back
#define MP make_pair
#define P pair

#if defined(__APPLE__)
#include <unistd.h>
#endif

#define TIME_TEST
#include <calcTime.h>
#include <rand.h>

using namespace std;

struct strtab_cmp
{
    typedef  vector<char>::iterator  strtab_iterator;

    bool operator()( const pair<strtab_iterator, strtab_iterator>& x,
                       const pair<strtab_iterator, strtab_iterator>& y ) const {
        return lexicographical_compare( x.first, x.second, y.first, y.second );
    }
};

struct strtab_print
{
    typedef  vector<char>::iterator strtab_iterator;
    ostream& out;

    strtab_print(ostream&  os) : out (os) {}

    void operator()( const pair<strtab_iterator, strtab_iterator>&  s ) const {
        copy( s.first, s.second, ostream_iterator<char>(cout) );
    }
};

int main(int argc, char* argv[])
{
    #if defined(__APPLE__)
    setvbuf(stdout, NULL, _IONBF, 0);
    #endif

    // Create string table
    vector <char> strtab;
    char c;

    T_START();
    while (cin.get(c)) {
        strtab.PB(c);
    }
    T_END();

    T_SEC_gnu(argv[1]);

    // Parse the string table into lines.
    using strtab_iterator = vector<char>::iterator;
    vector<pair<strtab_iterator, strtab_iterator>> lines;

    strtab_iterator  start = strtab.begin();

    T_START();
        while (start != strtab.end()) {
            strtab_iterator next = find( start, strtab.end(), '\n' );

            if (next != strtab.end())
                ++next;
            lines.PB(MP( start, next ) );
            start = next;
        }
    T_END();


    /* Change the setting*/
    // T_SEC("Tokenize the string");
    T_SEC_gnu(argv[1]);

    // Sort the vector of lines
    T_START();
        sort( lines.begin(), lines.end(), strtab_cmp() );
    T_END();

    /* Change the setting*/
    // T_SEC("Sorting");
    T_SEC_gnu(argv[1]);

    // Write the lines to standard output

    T_START();
    for_each( lines.begin(), lines.end(), strtab_print(cout) );
    T_END();
    T_SEC_gnu(argv[1]);

    return 0;
}
