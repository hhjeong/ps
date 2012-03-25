#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <cstring>
typedef long long ll;
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

int N;

int cache[30][30][2][2];
vector< string > X, Y;

ll solve( int i, int j, int pi, int pj, string left, string right ) {
    if( i > j ) return is_pal( left + right );
    if( i == j ) {
        int ret = is_pal( left + X[i] + right );
        ret += is_pal( left + Y[i] + right );
        return ret;
    }

    if( ! is_ok( left, right ) ) return 0;


    int &ret = cache[i][j][pi][pj];

    if( ret != -1 ) {
        return ret;
    }

    ret = 0;

    ret += solve( i+1, j-1, 0, 0, left + X[i], X[j] + right );
    ret += solve( i+1, j-1, 1, 0, left + Y[i], X[j] + right );
    ret += solve( i+1, j-1, 0, 1, left + X[i], Y[j] + right );
    ret += solve( i+1, j-1, 1, 1, left + Y[i], Y[j] + right );

    return ret;
}
int main() {
    cin >> N;
    X.resize( N );
    Y.resize( N );

    for( int i = 0 ; i < N ; ++i ) cin >> X[i];
    for( int i = 0 ; i < N ; ++i ) cin >> Y[i];

    memset( cache, -1, sizeof cache );
    cout << solve( 0, N-1, 0, 0, "", "" ) << endl;
}

