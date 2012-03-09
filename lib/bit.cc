// Binary Indexed Tree(a.k.a. Fenwick Tree)
// coded by LIBe(libe_at_ajou.ac.kr)

// �Ʒ� �ΰ��� header file�� �ݵ�� �ʿ��ϴ�.
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


// Library - �̺κ��� �ǵ��� ����
template <typename T>

struct bitree {
    int N; vector<T> d;

    // constructor�� �̿��� �ʱ�ȭ, 1~N ������ �迭�� �̿��Ѵ�.
    bitree(int _N=0) { N = _N; d.resize(N+1); fill(d.begin(),d.end(),0LL); }

    // �ʱ�ȭ
    void init(int _N) { N = _N; d.resize(N+1); fill(d.begin(),d.end(),0LL); }

    // d[1~N] ������ �������� ���Ѵ�.
    T csum(int ix) {
        T res = d[0];
        while(ix>0) { res += d[ix]; ix &= (ix-1); }
        return res;
    }

    // binary indexed tree�� update ���ִ� routine
    void update(int ix, T val) {
        while(ix<=N) { d[ix] += val; ix += (ix&(-ix)); }
    }
};
// Library�� ��

int main() {
    int a[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // ������ ���� �����Ѵ�.
    bitree<int> bit(10);
    for(int i=1;i<=10;++i) {
        bit.update(i,a[i]);
    }

    printf("a = { 1,2,3,4,5,6,7,8,9,10 }\n");
    // a[1] ���� a[N]������ �������� Ȯ���ϴ� routine
    for(int i=1;i<=10;++i) {
        printf("sum[%2d..%2d] = %4d\n",1,i,bit.csum(i));
    }

    // �ʱ�ȭ
    bit.init(5);

    for(int i=1;i<=5;++i) {
        bit.update(i,a[i]+5);

    }

    printf("a = { 6,7,8,9,10 }\n");
    for(int i=1;i<=5;++i) {
        printf("sum[%2d..%2d] = %4d\n",1,i,bit.csum(i));
    }
}

