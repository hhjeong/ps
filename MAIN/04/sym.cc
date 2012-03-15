#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

bool is_ok( string A, string B ) {
    reverse( B.begin(), B.end() );

    int len = (int) min( A.size(), B.size() );

    for( int i = 0 ; i < len ; ++i ) {
        if( A[i] != B[i] ) {
            return false;
        }
    }
    return true;
}

bool is_pal( string S ) {
    string T = S;
    reverse( T.begin(), T.end() );

    return S == T;
}

map< pair< string,string >, int > cache;

vector< string > X, Y;

int solve( int i, int j, string left, string right ) {
    if( i > j ) return is_pal( left + right );
    if( i == j ) {
        int ret = is_pal( left + X[i] + right );
        ret += is_pal( left + Y[i] + right );
        return ret;
    }

    if( ! is_ok( left, right ) ) return 0;
    pair< string, string > state = make_pair( left, right );

    if( cache.count( state ) ) {
        return cache[ state ];
    }

    int &ret = cache[ state ];
    ret = 0;

    ret += solve( i+1, j-1, left + X[i], X[j] + right );
    ret += solve( i+1, j-1, left + Y[i], X[j] + right );
    ret += solve( i+1, j-1, left + X[i], Y[j] + right );
    ret += solve( i+1, j-1, left + Y[i], Y[j] + right );

    return ret;
}
int main() {
    int N;
    cin >> N;
    X.resize( N );
    Y.resize( N );

    for( int i = 0 ; i < N ; ++i ) cin >> X[i];
    for( int i = 0 ; i < N ; ++i ) cin >> Y[i];

    cout << solve( 0, N-1, "", "" ) << endl;
}
