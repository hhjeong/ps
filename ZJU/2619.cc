#include <iostream>
#include <map>
#include <cstdio>

using namespace std;
typedef long long ll;

map< pair<int,string>, long double > cache;
long double search( const int &howmany, const string &pat, const int &len, string last ) {
    if( last.size() > pat.size() ) {
       last = last.substr( 1 ); 
    }

    if( pat == last ) {
        if( len > 0 ) return 0;
        else return 1;
    }
    if( len == 0 ) return 0;

    pair<int,string> state = make_pair( len, last );
    if( cache.count( state ) ) return cache[state];

    long double &ret = cache[state] = 0;
    for( char c = 'A' ; c < 'A' + howmany ; ++c ) {
        ret += search( howmany, pat, len-1, last + c ); 
    }

    return ret;
}

long double solve( const int &N, const string &pat ) {

    long double exp = 0.0;
    for( int len = 1 ; len <= 10 ; ++len ) {
        long double tot = search( N, pat, len, "" );
        long double cur_exp = len * tot;
        long double pw = 1.0;
        for( int i = 0 ; i < len ; ++i ) pw *= N;

        cur_exp /= pw;
        cerr << len << " " << tot << " " << pw << endl;
        exp += cur_exp;
        // cerr << "DEBUG : " << tot << endl;
    }
    return exp;
}

int main() {
    freopen("2619.in","r",stdin);
    int ncase;
    cin >> ncase;

    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {
        int N;
        cache.clear();
        string pat;

        cin >> N >> pat;

        cout << solve( N, pat ) << endl;
    }
}

