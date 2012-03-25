#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int next[31][5] = {
	{ 1,  2,  3,  4,  5}, // 0
	{ 2,  3,  4,  5,  6}, // 1
	{ 3,  4,  5,  6,  7}, // 2
	{ 4,  5,  6,  7,  8}, // 3
	{ 5,  6,  7,  8,  9}, // 4
	{20, 21, 22, 23, 24}, // 5
	{ 7,  8,  9, 10, 11}, // 6
	{ 8,  9, 10, 11, 12}, // 7
	{ 9, 10, 11, 12, 13}, // 8
	{10, 11, 12, 13, 14}, // 9
	{25, 26, 22, 27, 28}, // 10
	{12, 13, 14, 15, 16}, // 11
	{13, 14, 15, 16, 17}, // 12
	{14, 15, 16, 17, 18}, // 13
	{15, 16, 17, 18, 19}, // 14
	{16, 17, 18, 19, 30}, // 15
	{17, 18, 19, 30, -1}, // 16
	{18, 19, 30, -1, -1}, // 17
	{19, 30, -1, -1, -1}, // 18
	{30, -1, -1, -1, -1}, // 19
	{21, 22, 23, 24, 15}, // 20
	{22, 23, 24, 15, 16}, // 21
	{27, 28, 30, -1, -1}, // 22
	{24, 15, 16, 17, 18}, // 23
	{15, 16, 17, 18, 19}, // 24
	{26, 22, 27, 28, 30}, // 25
	{22, 27, 28, 30, -1}, // 26
	{28, 30, -1, -1, -1}, // 27
	{30, -1, -1, -1, -1}, // 28
  { 1,  2,  3,  4,  5}, // start
  {-1, -1, -1, -1, -1}}; // last

int main() {
	int T;
	cin >> T;
	for (int cn = 1; cn <= T; ++cn) {
		int U, N, A, B;
		cin >> U >> N >> A >> B;
		int pa = 29, pb = 29;
		int turn = 0;
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			int dist;
			if (s == "Do") { dist = 0;
			} else if (s == "Gae") { dist = 1;
			} else if (s == "Gul") { dist = 2;
			} else if (s == "Yut") { dist = 3;
			} else if (s == "Mo") { dist = 4;
			}
			if (turn == 0) {
				pa = next[pa][dist];
				if (dist < 3 && pa != pb) turn = 1 - turn;
				if (pa == pb) { pb = 29; }
			} else {
				pb = next[pb][dist];
				if (dist < 3 && pa != pb) turn = 1 - turn;
				if (pa == pb) { pa = 29; }
			}
		}
		int sa = -1, sb = -1;
		if (A == 1) cin >> sa;
		if (B == 1) cin >> sb;
//		printf("%d,%d,%d,%d\n", pa, pb, sa, sb);
		if (sa == -1 && pa == 29) sa = 29;
		if (sb == -1 && pb == 29) sb = 29;
		if (pa == 30) sa = 0;
		if (pb == 30) sb = 0;
		if (sa == pa && sb == pb) {
			printf("Case #%d: YES\n", cn);
		} else {
			printf("Case #%d: NO\n", cn);
		}
	}
}


