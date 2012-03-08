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

int N, M, K;
int S[5];
int total;
char F[10][10];
double sum;

int go( int i, int j ) {
    
    int horz = 1;
    for( int k = j+1 ; k < M ; ++k ) {
        if( F[i][j] == F[i][k] ) ++horz;
        else break;
    }

    for( int k = j-1 ; k >= 0 ; --k ) {
        if( F[i][j] == F[i][k] ) ++horz;
        else break;
    }

    int vert = 1;
    for( int k = i+1 ; k < N ; ++k ) {
        if( F[i][j] == F[k][j] ) ++vert;
        else break;
    }

    for( int k = i-1 ; k >= 0 ; --k ) {
        if( F[i][j] == F[k][j] ) ++vert;
        else break;
    }

    int da = 1;
    for( int k = 1 ; i+k < N && j+k < M ; ++k ) {
        if( F[i][j] == F[i+k][j+k] ) ++da;
            else break;
    }

    for( int k = 1 ; i-k >= 0 && j-k >= 0 ; ++k ) {
        if( F[i][j] == F[i-k][j-k] ) ++da;
        else break;
    }

    int db = 1;
    for( int k = 1 ; i+k < N && j-k >= 0 ; ++k ) {
        if( F[i][j] == F[i+k][j-k] ) ++db;
            else break;
    }

    for( int k = 1 ; i-k >= 0 && j+k < M ; ++k ) {
        if( F[i][j] == F[i-k][j+k] ) ++db;
            else break;
    }

    return min( 4, max( max( horz, vert ) , max( da, db ) ) );
}

void calc() {
    int all = 0;
    for( int i = 0 ; i < N ; ++i ) {
        for( int j = 0 ; j < M ; ++j ) {
            all += S[go( i, j )];
        }
    }
    sum += (double)all / total;
}

void solve( int i, int j ) {
    if( i >= N ) {
        calc();
        return;
    }
    if( j >= M ) {
        solve( i+1, 0 );
        return;
    }

    if( F[i][j] == '?' ) {
        for( F[i][j] = '1' ; F[i][j] <= '0' + K ; ++F[i][j] ) {
            solve( i, j+1 );
        }
        F[i][j] = '?';
    }
    else {
        solve( i, j + 1);
    }
}
int main() {
    clock_t start_time = clock();
    //freopen("B.in","r",stdin);

    int ncase;
    scanf("%d", &ncase); 

    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {
        printf("Case #%d: ", caseno);
        cin >> N >> M >> K;
        cin >> S[4] >> S[3] >> S[2];
        S[1] = S[0] = 0;

        total = 1;
        sum = 0;
        for( int i = 0 ; i < N ; ++i ) cin >> F[i];
        for( int i = 0 ; i < N ; ++i ) {
            for( int j = 0 ; j < M ;++j ) {
                if( F[i][j] == '?' ) total *= K;
            }
        }
        solve( 0, 0 );
        printf("%.8f\n", sum );
		fprintf(stderr,"%d/%d\n", caseno, ncase);
    }
    fprintf(stderr,"Elapsed time : %.3fsec\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);    
}
