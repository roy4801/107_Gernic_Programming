#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <ctime>

#define TIME

using namespace std;

class line_iterator
{
    istream*  in;
    string   line;
    bool     at_end;

    void read( ) {
        if (*in)
            getline(*in, line);
        at_end = (*in) ? true : false;
    }

public:
    typedef  input_iterator_tag  iterator_category;
    typedef  string  value_type;
    typedef  ptrdiff_t  difference_type;
    typedef  const string*  pointer;
    typedef  const string&  reference;

    line_iterator( ) : in(&cin), at_end(false) { }
    line_iterator(istream& s) : in(&s) { read( ); }
    reference operator*( ) const { return line; }
    pointer operator->( ) const { return &line; }

    line_iterator operator++( ) {  // prefix ++
        read( );
        return *this;
    }

    line_iterator operator++(int) {  // postfix ++
        line_iterator  tmp = *this;
        read();
        return tmp;
    }

    bool operator==(const line_iterator& i) const {
        return (in == i.in && at_end == i.at_end) ||
               (at_end == false && i.at_end == false);
    }

    bool operator!=(const line_iterator& i) const {
        return !(*this == i);
    }
}; // end  of class line_iterator

int  main()
{
    clock_t start = clock();

    line_iterator  iter(cin);
    line_iterator  end_of_file;

    vector<string>  V(iter, end_of_file);

    sort( V.begin(), V.end() ); // sort( V.begin(), V.end(), greater<string>() );
    copy( V.begin(), V.end(), ostream_iterator<string>(cout, "\n"));

    cout << ((float)clock() - start) / CLOCKS_PER_SEC << " sec" << endl;

    return 0;
}
