#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

const int inf = 987654321;
int N;
int P[7];
int R[7][7];

int order[101];
bool used[101][101][101];
int cache[101][101][101];

int solve( int now, int P1, int P2 ) {
    if( now == N ) return 0;
    int P3 = N - now - P1 - P2;

    int &ret = cache[now][P1][P2];
    if( used[now][P1][P2] ) return ret;
    used[now][P1][P2] = true;
    ret = -inf;
    int now_enemy = order[now];
    
    if( P1 > 0 ) {
        ret = max( ret, solve( now+1, P1-1, P2 ) + R[1][now_enemy] );
    }
    
    if( P2 > 0 ) {
        ret = max( ret, solve( now+1, P1, P2-1 ) + R[2][now_enemy] );
    }

    if( P3 > 0 ) {
        ret = max( ret, solve( now+1, P1, P2 ) + R[3][now_enemy] );
    }

    return ret;
}
int main() {
    clock_t start_time = clock();
    //freopen("A.in","r",stdin);

    int ncase;
    scanf("%d", &ncase); 

    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {
        cin >> N;
        for( int i = 1 ; i <= 6 ; ++i ) cin >> P[i];

        for( int i = 1 ; i <= 3 ; ++i  ) {
            for( int j = 4 ; j <= 6 ; ++j ) {
                cin >> R[i][j];
            }
        }

        int p = 0;

        for( int i = 0 ; i < P[4] ; ++i ) order[p++] = 4;
        for( int i = 0 ; i < P[5] ; ++i ) order[p++] = 5;
        for( int i = 0 ; i < P[6] ; ++i ) order[p++] = 6;

        memset( used, 0, sizeof used );
        printf("Case #%d: ", caseno);
        printf("%d\n",solve( 0, P[1], P[2] ));
		fprintf(stderr,"%d/%d\n", caseno, ncase);
    }
    fprintf(stderr,"Elapsed time : %.3fsec\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);    
}
