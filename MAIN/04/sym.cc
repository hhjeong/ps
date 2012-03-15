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

int N;
map< pair< string,string >, int > cache;

vector< string > X, Y;

int right( int j, string S, string T ) {
    if( j == N / 2 ) {
        return is_pal( S + T );
    }
    if( ! is_ok( S, T ) ) return 0;
    return right( j-1, S, X[j] + T ) + right( j-1, S, Y[j] + T );
}

int left( int i, string S ) {
    if( i > N/2 ) {
        return right( N-1, S, "" );
    }

    return left( i+1, X[i] ) + left( i+1, Y[i] );
}
int main() {
    cin >> N;
    X.resize( N );
    Y.resize( N );

    for( int i = 0 ; i < N ; ++i ) cin >> X[i];
    for( int i = 0 ; i < N ; ++i ) cin >> Y[i];

    cout << left( 0, "" ) << endl;
}

