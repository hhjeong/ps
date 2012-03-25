#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
char yut[128];

int Status[2][31][31][31][31], Next[2][31][31][31][31];
int Move[31][5];

void init(){
	int i, j;
	for(i=0;i<=19;i++){
		for(j=0;j<5;j++) Move[i][j] = i + j + 1;
	}
	Move[15][4] = 29;
	
	Move[16][3] = 29;
	Move[16][4] = 30;

	Move[17][2] = 29;
	Move[17][3] = 30;
	Move[17][4] = 30;
	
	Move[18][1] = 29;
	Move[18][2] = 30;
	Move[18][3] = 30;
	Move[18][4] = 30;
	
	Move[19][0] = 29;
	Move[19][1] = 30;
	Move[19][2] = 30;
	Move[19][3] = 30;
	Move[19][4] = 30;

	Move[5][0] = 20;
	Move[5][1] = 21;
	Move[5][2] = 22;
	Move[5][3] = 23;
	Move[5][4] = 24;

	Move[20][0] = 21;
	Move[20][1] = 22;
	Move[20][2] = 23;
	Move[20][3] = 24;
	Move[20][4] = 15;
	
	Move[21][0] = 22;
	Move[21][1] = 23;
	Move[21][2] = 24;
	Move[21][3] = 15;
	Move[21][4] = 16;

	Move[23][0] = 24;
	Move[23][1] = 15;
	Move[23][2] = 16;
	Move[23][3] = 17;
	Move[23][4] = 18;
	
	Move[24][0] = 15;
	Move[24][1] = 16;
	Move[24][2] = 17;
	Move[24][3] = 18;
	Move[24][4] = 19;

	Move[10][0] = 25;
	Move[10][1] = 26;
	Move[10][2] = 22;
	Move[10][3] = 27;
	Move[10][4] = 28;
	
	Move[25][0] = 26;
	Move[25][1] = 22;
	Move[25][2] = 27;
	Move[25][3] = 28;
	Move[25][4] = 29;
	
	Move[26][0] = 22;
	Move[26][1] = 27;
	Move[26][2] = 28;
	Move[26][3] = 29;
	Move[26][4] = 30;
	
	Move[22][0] = 27;
	Move[22][1] = 28;
	Move[22][2] = 29;
	Move[22][3] = 30;
	Move[22][4] = 30;
	
	Move[22][0] = 27;
	Move[22][1] = 28;
	Move[22][2] = 29;
	Move[22][3] = 30;
	Move[22][4] = 30;
	
	Move[27][0] = 28;
	Move[27][1] = 29;
	Move[27][2] = 30;
	Move[27][3] = 30;
	Move[27][4] = 30;
	
	Move[28][0] = 29;
	Move[28][1] = 30;
	Move[28][2] = 30;
	Move[28][3] = 30;
	Move[28][4] = 30;

	Move[29][0] = 30;
	Move[29][1] = 30;
	Move[29][2] = 30;
	Move[29][3] = 30;
	Move[29][4] = 30;
}

bool match(int x,int y) {
	if (x == -1) {
		return y == 0 || y == 30;
	}
	return x == y;
}

int main(){
	//freopen("B-small-attempt1.in","r",stdin);
	//freopen("B-small-attempt1.out","w",stdout);
	init();
	int T;
	scanf("%d",&T);
	while(T-- > 0){
		int U, N, A, B;
		scanf("%d %d %d %d",&U,&N,&A,&B);
		int i, t, Y, a, b, c, d;
		memset(Status, 0, sizeof(Status));
		Status[0][0][0][0][0] = true; // 0 은 보드 어디에도 없는것, 출발도 안했음.
		// 30은 보드에는없는 이유가 도착했기 때문.
		// 29는 보드에 마지막 도착.

		for(i=0;i<N;i++){
			scanf("%s", yut);
			if (!strcmp(yut, "Do"))	Y = 0;
			if (!strcmp(yut, "Gae"))	Y = 1;
			if (!strcmp(yut, "Gul"))	Y = 2;
			if (!strcmp(yut, "Yut"))	Y = 3;
			if (!strcmp(yut, "Mo"))	Y = 4;
			// TODO : t가 Y액션을 함.
			memset(Next, 0, sizeof(Next));
			for(t=0;t<2;t++) {
			for(a=0;a<31;a++){
				for(b=0;b<31;b++){
					for(c=0;c<31;c++){
						for(d=0;d<31;d++){
							if (Status[t][a][b][c][d]) {
								if (t == 0) // A팀
								{
									if (a == b && a != 0 && a != 30) { // 출발도 완전 끝도 아니지만 업어가는 상황 ㅋ
										int da = Move[a][Y];
										int dd = d, dc = d;
										int tt;
										tt = 1-t;
										if (Y == 3 || Y == 4) tt = t;
										if (da != 30 && dc == da){ dc = 0; tt = t;}
										if (da != 30 && dd == da){ dd = 0; tt = t;}
										Next[tt][da][da][dc][dd] = true;
									} else if (a != b || a == 0){
										if (a != 30) {
											int da = Move[a][Y], dc=c , dd=d;
											int tt;
											tt = 1-t;
											if (Y == 3 || Y == 4) tt = t;
											if (da != 30 && dc == da) {dc = 0;tt = t;}
											if (da != 30 && dd == da) {dd = 0;tt = t;}
											Next[tt][da][b][dc][dd] = true;
										}
										if (U > 1) {
											if (b != 30) {
												int db = Move[b][Y], dc=c ,dd=d;
												int tt;
												tt = 1-t;
												if (Y == 3 || Y == 4) tt = t;
												if (db != 30 && dc == db){ dc = 0;tt = t;}
												if (db != 30 && dd == db){ dd = 0;tt = t;}
												
												Next[tt][a][db][dc][dd] = true;
											}
										}
									}
								}
								else {
									if (c == d && c != 0 && c != 30) { // 출발도 완전 끝도 아니지만 업어가는 상황 ㅋ
										int dc = Move[c][Y], da = a, db = b, tt;
										tt = 1-t;
										if (Y == 3 || Y == 4) tt =t;
										if (dc != 30 && da == dc){ da = 0;tt = t;}
										if (dc != 30 && db == dc){ db = 0;tt = t;}
										Next[tt][da][db][dc][dc] = true;
									} else if (c != d || c == 0){
										if (c != 30) {
											int dc = Move[c][Y], da=a , db=b, tt;
											tt = 1-t;
											if (Y == 3 || Y == 4) tt = t;
											if (dc != 30 && da == dc){ da = 0;tt =t;}
											if (dc != 30 && db == dc){ db = 0;tt = t;}
											Next[tt][da][db][dc][d] = true;
										}
										
										if (U > 1) {
											if (d != 30) {
												int dd = Move[d][Y], da=a ,db=b, tt;
												tt = 1-t;
												if (Y == 3 || Y == 4) tt = t;
												if (dd != 30 && da == dd){ da = 0;tt = t;}
												if (dd != 30 && db == dd){ db = 0;tt = t;}
												Next[tt][da][db][c][dd] = true;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			}

			for(t=0;t<2;t++){
			for(a=0;a<31;a++){
				for(b=0;b<31;b++){
					for(c=0;c<31;c++){
						for(d=0;d<31;d++){
							Status[t][a][b][c][d] = Next[t][a][b][c][d];
						}
					}
				}
			}
			}
			// FILL
		}
		int AM[2], BM[2];
		for(i=0;i<A;i++){
			scanf("%d", &AM[i]);
			if (AM[i] == 0) AM[i] = 29;
		}
		for(;i<2;i++) AM[i] = -1;
		for(i=0;i<B;i++){
			scanf("%d", &BM[i]);
			if (BM[i] == 0) BM[i] = 29;
		}
		for(;i<2;i++) BM[i] = -1;

		bool How = false;
		for(t=0;t<2;t++){
		for (a=0;a<31;a++){
			if (!match(AM[0], a)) continue;
			for(b=0;b<31;b++){
				if (!match(AM[1], b)) continue;
				for(c=0;c<31;c++) {
					if (!match(BM[0], c)) continue;
					for(d=0;d<31;d++){
						if (!match(BM[1], d)) continue;
						How = How || Status[t][a][b][c][d];
					}
				}
			}
		}
		}
		static int cs = 1;
		printf("Case #%d: %s\n", cs++, How?"YES":"NO");
	}
	return 0;
}

