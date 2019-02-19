#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <ctime>

#define SIMPLE

#define TIME

using namespace std;

#ifdef SIMPLE
int main() {
    vector<string> V;      // Container
    string tmp;

#ifdef TIME
    clock_t t;

    t = clock();
#endif

    while ( getline(cin, tmp) )
         V.push_back(tmp);

#ifdef TIME
    t = clock() - t;
    cout << "Input took " << t << " clicks (" << ((float) t)/CLOCKS_PER_SEC << " seconds).\n";
    t = clock();
#endif
    // sort its argument in ascending order
    sort( V.begin(), V.end() ); //, greater<string>() );     // Iterator & Algorithm

#ifdef TIME
    t = clock() - t;
    cout << "Sorting took " << t << " clicks (" << ((float) t)/CLOCKS_PER_SEC << " seconds).\n";
    t = clock();
#endif

    copy( V.begin(), V.end(), ostream_iterator<string>(cout, "\n") );

#ifdef TIME
    t = clock() - t;
    cout << "Output took " << t << " clicks (" << ((float) t)/CLOCKS_PER_SEC << " seconds).\n";
#endif

    return 0;
}

#endif
