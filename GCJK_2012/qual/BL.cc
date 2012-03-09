#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

string best;

string rm( const string &s ) {
    string ret = s;
    while( (int)ret.size() > 1 && ret[0] == '0' ) {
        ret = ret.substr(1);
    }
    return ret;
}

int getlo( int i, const string &s  ){
    if( isdigit( s[i] ) ) return (int)(s[i]-'0');
    if( s[i] == '#' ) return 0;

    if( (int)s.size() == 1 ) return 0;
    if( i == 0 ) return 1;
    if( s[i-1] == '#' && i != (int)s.size() - 1 ) return 1;
    return 0;
}

int gethi( int i, const string &s ) {
    if( isdigit( s[i] ) ) return (int)(s[i]-'0');
    if( s[i] == '#' ) return 0;
    return 9;
}

int sign;
string lf;
string rt;
string ans;

typedef pair< pair<string,string>, string > node;
node cache[2][10][10][10][251];

const node nil = make_pair( make_pair( "", "" ), "" );
const node fail = make_pair( make_pair( "", "" ), "FAIL" );
node solve( int where, int carry, int pl, int pr, int pa ) {
    //for(int i=0;i<where;++i) fprintf( stderr, " ");
    //fprintf( stderr, "solve(%d/%d,%d,%d,%d,%d)", where, (int)ans.size(), carry, pl, pr, pa );
    if( where == ans.size() ) {
        //for(int i=0;i<where;++i) fprintf( stderr, " ");
        //fprintf(stderr,"=> %s\n", ( carry ? "O" : "X" ) );
        if( carry == 0 ) return nil;
        return fail;
    }
    //cerr << endl;
   
    int l1 = getlo( where, lf ), l2 = gethi( where, lf );
    int r1 = getlo( where, rt ), r2 = gethi( where, rt );
    int a1 = getlo( where, ans ), a2 = gethi( where, ans );

    node &ret = cache[carry][pl][pr][pa][where];
    if( ret != nil ) return ret;
    ret = fail;

    //for(int i=0;i<where;++i) fprintf( stderr, " ");
    //fprintf( stderr, "%d, %c[%d,%d], %c[%d,%d], %c[%d,%d]\n", where, lf[where], l1, l2, rt[where], r1, r2, ans[where], a1, a2 );
    for( int l = l1 ; l <= l2 ; ++l ) for( int r = r1 ; r <= r2 ; ++r ) for( int a = a1 ; a <= a2 ; ++a ) for( int c = 0 ; c <= 1 ; ++c ) {
        
        int v = l + sign * ( r + c );
        //cerr << v << " " << l << " " << r << " " << a << " " << c << endl;
        if( carry == 1 ) {
            if( sign == 1 ) {
                if( v < 10 ) continue;
            }
            else {
                if( v >= 0 ) continue;
                v += 10;
            }
        }        
        else {
            if( sign == 1 ) {
                if( v >= 10 ) continue;
            }
            else if ( v < 0 ) continue;
        }
        if( v % 10 == a ) {
            // for(int i=0;i<where;++i) fprintf( stderr, " ");
            // fprintf( stderr, "%d %d + %d = %d\n", c, l, r, a );
            node ans = solve( where+1, c, l, r, a ); 
            if( ans != fail ) {
                ans.first.first = string(1,char(l+'0')) + ans.first.first;
                ans.first.second = string(1,char(r+'0')) + ans.first.second;
                ans.second = string(1,char(a+'0')) + ans.second;
                if( ret == fail || ret > ans ) ret = ans;
            }
        }
    }
    return ret;

}

int main() {
    clock_t start_time = clock();
    freopen("B.in","r",stdin);

    int ncase;
    scanf("%d", &ncase); 

    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {
        string op, foo;
        cin >> lf >> op >> rt;
        cin >> foo >> ans;

        best = "";
        int max_len = max( (int)ans.size(), (int)lf.size() );
        max_len = max( max_len, (int)rt.size() );

        while( (int)lf.size() < max_len ) lf = '#' + lf;
        while( (int)rt.size() < max_len ) rt = '#' + rt;
        while( (int)ans.size() < max_len ) ans = '#' + ans;

        for( int i = 0 ; i < 2 ; ++i ) for( int l = 0 ; l < 10 ; ++l ) for(int r = 0 ; r < 10 ; ++r ) for( int a = 0 ; a < 10 ; ++ a ) for( int p = 0 ; p < max_len ; ++p ) cache[i][l][r][a][p] = nil;
        printf("Case #%d: ", caseno);
        if( op == "+" ) sign = 1; else sign = -1;
        node ret = solve( 0, 0, 0, 0, 0);
        cout << rm(ret.first.first) << " " << op << " " << rm(ret.first.second) << " = " << rm(ret.second) << endl;
		fprintf(stderr,"%d/%d\n", caseno, ncase);
    }
    fprintf(stderr,"Elapsed time : %.3fsec\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);    
}
