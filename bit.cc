// Binary Indexed Tree(a.k.a. Fenwick Tree)
// coded by LIBe(libe_at_ajou.ac.kr)

// 아래 두가지 header file은 반드시 필요하다.
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


// Library - 이부분은 건들지 말것
template <typename T>

struct bitree {
    int N; vector<T> d;

    // constructor를 이용한 초기화, 1~N 범위의 배열을 이용한다.
    bitree(int _N=0) { N = _N; d.resize(N+1); fill(d.begin(),d.end(),0LL); }

    // 초기화
    void init(int _N) { N = _N; d.resize(N+1); fill(d.begin(),d.end(),0LL); }

    // d[1~N] 까지의 누적합을 구한다.
    T csum(int ix) {
        T res = d[0];
        while(ix>0) { res += d[ix]; ix &= (ix-1); }
        return res;
    }

    // binary indexed tree를 update 해주는 routine
    void update(int ix, T val) {
        while(ix<=N) { d[ix] += val; ix += (ix&(-ix)); }
    }
};
// Library의 끝

int main() {
    int a[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // 다음과 같이 선언한다.
    bitree<int> bit(10);
    for(int i=1;i<=10;++i) {
        bit.update(i,a[i]);
    }

    printf("a = { 1,2,3,4,5,6,7,8,9,10 }\n");
    // a[1] 부터 a[N]까지의 누적값을 확인하는 routine
    for(int i=1;i<=10;++i) {
        printf("sum[%2d..%2d] = %4d\n",1,i,bit.csum(i));
    }

    // 초기화
    bit.init(5);

    for(int i=1;i<=5;++i) {
        bit.update(i,a[i]+5);

    }

    printf("a = { 6,7,8,9,10 }\n");
    for(int i=1;i<=5;++i) {
        printf("sum[%2d..%2d] = %4d\n",1,i,bit.csum(i));
    }
}

