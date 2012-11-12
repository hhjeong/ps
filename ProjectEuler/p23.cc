#include <cstdio>

const int bound = 28123;
bool isabundant[bound+1];

int main() {
    for( int i = 1 ; i <= bound ; ++i ) {
        int sum_div = 0;
        for( int j = 1 ; j * j <= i ; ++j ) {
            if( i % j == 0 ) {
                sum_div += j;
                if( j * j != i && j > 1 ) sum_div += i / j;
            }
        }
        isabundant[i] = (sum_div > i);
    }    
    
    int sum = 0;
    for( int i = 1 ; i <= bound ; ++i ) {
        bool ok = false;
        for( int j = 1 ; j < i ; ++j ) {
            if( isabundant[j] && isabundant[i-j] ) {
                printf("%d=%d+%d\n", i, j, i-j);
                ok = true;
                break;
            }
        }
        if( !ok ) {
            printf("%d\n", i);
            sum += i;
        }
    }
    printf("ans : %d\n", sum);
}
