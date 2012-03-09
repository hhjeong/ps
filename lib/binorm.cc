#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

long long comb(long long r, long long c) {
    if( c > r-c ) return comb( r, r-c );
	long long ret = 1;
	long long div = 1;
	long long tc = 1;
	for(long long i=0;i<c;++i) {
		ret *= r--;
		div *= tc++;
		long long gcd = __gcd(ret,div);
		ret /= gcd;
		div /= gcd;
	}
	return ret;
}

vector< vector< long long > > get_pascal_triangle( int N ) {
    vector< vector< long long > > ret;
    ret.push_back( vector< long long >( 1, 1 ) ); // C(0,0) = 1

    for( int n = 1 ; n <= N ; ++n ) {
        vector< long long > cur;
        cur.push_back( 1 ); // C(N,0)

        for( int m = 1 ; m < n ; ++m ) {
            cur.push_back( ret.back()[m-1] + ret.back()[m] );
        }
        cur.push_back( 1 ); // C(N,N)

        ret.push_back( cur );
    }

    return ret;
}

int main() {
    vector< vector< long long > > C = get_pascal_triangle( 60 ); // works N <= 60

    for( int i = 0 ; i < C.size() ; ++i ) {
        for( int j = 0 ; j < C[i].size() ; ++j ) {
            if( C[i][j] != comb( i, j ) ) {
                cout << "Error at " << i << "," << j << endl;
                assert(false);
            }
        }
    }
    cout << "Test passed!" << endl;
}

