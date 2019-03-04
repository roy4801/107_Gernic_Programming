#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <ctime>

#define TIME_TEST
#include <calcTime.h>
#include <rand.h>

using namespace std;

int main(int argc, char* argv[]) {
    vector<string> V;      // Container
    string tmp;


    //input
    T_START();
    while ( getline(cin, tmp) )
         V.push_back(tmp);
    T_END();

    /* Change the setting*/
    // T_SEC("Tokenize the string");
    T_SEC_gnu(argv[1]);

    // cout << "Input took " << t << " clicks (" << ((float) t)/CLOCKS_PER_SEC << " seconds).\n";
    // t = clock();

    // sort its argument in ascending order
    T_START();
    sort( V.begin(), V.end() ); //, greater<string>() );     // Iterator & Algorithm
    T_END();

    /* Change the setting*/
    // T_SEC("Sorting");
    T_SEC_gnu(argv[1]);

    T_START();
    // cout << "Sorting took " << t << " clicks (" << ((float) t)/CLOCKS_PER_SEC << " seconds).\n";
    // t = clock();

    copy( V.begin(), V.end(), ostream_iterator<string>(cout, "\n") );

    // cout << "Output took " << t << " clicks (" << ((float) t)/CLOCKS_PER_SEC << " seconds).\n";
    T_END();

    T_SEC_gnu(argv[1]);
    return 0;
}

