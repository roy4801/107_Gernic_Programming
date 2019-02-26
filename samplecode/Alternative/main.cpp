#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <ctime>

#define TIME
#define PB push_back
#define MP make_pair
#define P pair

using namespace std;


struct  strtab_cmp
{
    typedef  vector<char>::iterator  strtab_iterator;

    bool  operator()( const pair<strtab_iterator, strtab_iterator>& x,
                       const pair<strtab_iterator, strtab_iterator>& y ) const {
        return lexicographical_compare( x.first, x.second, y.first, y.second );
    }
};

struct  strtab_print
{
    typedef  vector<char>::iterator strtab_iterator;
    ostream& out;

    strtab_print(ostream&  os) : out (os) {}

    void  operator()( const pair<strtab_iterator, strtab_iterator>&  s ) const {
        copy( s.first, s.second, ostream_iterator<char>(cout) );
    }
};


int main()
{
    vector <char> strtab;	   // Create string table
    typedef  vector<char>::iterator  strtab_iterator;
    char c;

    while (cin.get(c)) {
        strtab.PB(c);
    }

    // Parse the string table into lines.
    vector< P<strtab_iterator, strtab_iterator> > lines;
    strtab_iterator  start = strtab.begin();

    while (start != strtab.end()) {
        strtab_iterator next = find( start, strtab.end(), '\n' );

        if (next != strtab.end())
            ++next;
        lines.PB(MP( start, next ) );
        start = next;
    }

    #ifdef TIME
    clock_t t;
    t = clock();
    #endif

    // Sort the vector of lines
    sort( lines.begin(), lines.end(), strtab_cmp() );//function object

    #ifdef TIME
    t = clock() - t;
    cout << "sort time:" << ((float) t)/CLOCKS_PER_SEC << " seconds.\n";
    t = clock();
    #endif

    // Write the lines to standard output
    for_each( lines.begin(), lines.end(), strtab_print(cout) );

    return 0;
}
