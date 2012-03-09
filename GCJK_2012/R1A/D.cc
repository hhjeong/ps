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
#include <cstring>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

int sieve[int(1e6)+1];
int makne[int(1e6)+1];

void pre_sieve() {
    const int N = int(1e6);
    memset( sieve, 0, sizeof sieve );
    memset( makne, -1, sizeof makne );
    for( int  i = 2 ; i <= N ; ++i ) {
        for( int j = i * 2 ; j <= N ; j += i ) {
            sieve[j]++;
            if( makne[j] == -1 || makne[j] > i ) makne[j] = i;
        }
    }
}

int solve( int N, int M ) {
    int ret = 0;
    for( int i = 2 ; i < N ; ++i ) {
        if( sieve[i] == sieve[N] && makne[i] >= M ) ++ret;
    }
    return ret;
}

int main() {
    clock_t start_time = clock();
    //freopen("D.in","r",stdin);

    int ncase;
    scanf("%d", &ncase); 

    pre_sieve();
    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {
        printf("Case #%d: ", caseno);
        int N, M;
        cin >> N >> M;
        cout << solve( N, M ) << endl;
		fprintf(stderr,"%d/%d\n", caseno, ncase);
    }
    fprintf(stderr,"Elapsed time : %.3fsec\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);    
}
