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

int main() {
    clock_t start_time = clock();
    freopen("B.in","r",stdin);

    int ncase;
    scanf("%d", &ncase); 

    for( int caseno = 1 ; caseno <= ncase ; ++caseno ) {
        printf("Case #%d: ", caseno);
		fprintf(stderr,"%d/%d\n", caseno, ncase);
    }
    fprintf(stderr,"Elapsed time : %.3fsec\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);    
}
