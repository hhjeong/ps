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

string remove( const string &s ) {
    string ret;
    for( int i = 0 ; i < (int)s.size() ; ++i ) if( s[i] != '#' ) ret += s[i];
    reverse( ret.begin(), ret.end() );
    return ret;
}

int getlo( int i, const string &s  ){
    if( isdigit( s[i] ) ) return (int)(s[i]-'0');
    if( s[i] == '#' ) return 0;

    if( (int)s.size() == 1 ) return 0;
    if( s[1] == '#' ) return 0;
    if( i == (int)s.size()-1 || s[i+1] == '#' ) return 1;
    return 0;
}

int gethi( int i, const string &s ) {
    if( isdigit( s[i] ) ) return (int)(s[i]-'0');
    if( s[i] == '#' ) return 0;
    return 9;
}

void solve_add( int where, int carry, string &left, string &right, string &ans ) {
    if( where == (int)ans.size() ) {
        if( carry == 0 ) {
            string expr = remove( left ) + " + " + remove( right ) + " = " + remove( ans );
            if( best == "" || best > expr ) best = expr;
        }
        return;
    }
    
    int l1 = getlo( where, left ), l2 = gethi( where, left );
    int r1 = getlo( where, right ), r2 = gethi( where, right );
    int a1 = getlo( where, ans ), a2 = gethi( where, ans );

    for( int l = l1 ; l <= l2 ; ++l ) for( int r = r1 ; r <= r2 ; ++r ) for( int a = a1 ; a <= a2 ; ++a ) {
        if( (l+r+carry) % 10 == a ) {
            bool lf = false;
            bool rf = false;
            bool af = false;
            if( left[where] == '?' ) left[where] = l + '0', lf = true;
            if( right[where] == '?' ) right[where] = r + '0', rf = true;
            if( ans[where] == '?' ) ans[where] = a + '0', af = true;
            solve_add( where+1, (l+r+carry) / 10, left, right, ans ); 
            if( lf ) left[where] = '?';
            if( rf ) right[where] = '?';
            if( af ) ans[where] = '?';
            
        }
    }
}

void solve_minus( int where, int nocarry, string &left, string &right, string &ans ) {
    if( where == (int)ans.size() ) {
        if ( nocarry == 0 ) {
            string expr = remove( left ) + " - " + remove( right ) + " = " + remove( ans );
            if( best == "" || best > expr ) best = expr;
        }
        return;
    }
    
    int l1 = getlo( where, left ), l2 = gethi( where, left );
    int r1 = getlo( where, right ), r2 = gethi( where, right );
    int a1 = getlo( where, ans ), a2 = gethi( where, ans );

    for( int l = l1 ; l <= l2 ; ++l ) for( int r = r1 ; r <= r2 ; ++r ) for( int a = a1 ; a <= a2 ; ++a ) {
        if( (l-r+nocarry) % 10 == a || (l-r+nocarry+10) % 10 == a ) {
            bool lf = false;
            bool rf = false;
            bool af = false;
            if( left[where] == '?' ) left[where] = l + '0', lf = true;
            if( right[where] == '?' ) right[where] = r + '0', rf = true;
            if( ans[where] == '?' ) ans[where] = a + '0', af = true;
            solve_minus( where+1, (l-r+nocarry) < 0 ? -1 : 0, left, right, ans ); 
            if( lf ) left[where] = '?';
            if( rf ) right[where] = '?';
            if( af ) ans[where] = '?';
            
        }
    }
}

int main() {
    clock_t start_time = clock();
    // freopen("B.in","r",stdin);

    int ncase;
    scanf("%d", &ncase); 

    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {
        string left, right, ans, op, foo;
        cin >> left >> op >> right;
        cin >> foo >> ans;

        reverse( left.begin(), left.end() );
        reverse( right.begin(), right.end() );
        reverse( ans.begin(), ans.end() );

        best = "";
        int max_len = max( (int)ans.size(), (int)left.size() );
        max_len = max( max_len, (int)right.size() );

        while( (int)left.size() < max_len ) left += "#";
        while( (int)right.size() < max_len ) right += "#";
        while( (int)ans.size() < max_len ) ans += "#";

        printf("Case #%d: ", caseno);
        if( op == "+" ) {
            solve_add( 0, 0, left, right, ans );
        }
        else {
            solve_minus( 0, 0, left, right, ans );

        }
        cout << best << endl;
		fprintf(stderr,"%d/%d\n", caseno, ncase);
    }
    fprintf(stderr,"Elapsed time : %.3fsec\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);    
}

