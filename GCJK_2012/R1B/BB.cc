#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int NOT_STARTED = -1;
const int FINISHED = 29;

struct state_s
{
	int idx;
	int turn;
	int pos[2][2];

	state_s(unsigned int v)
	{
		turn = v % 2; v /= 2;
		pos[1][1] = v % 31 - 1; v /= 31;
		pos[1][0] = v % 31 - 1; v /= 31;
		pos[0][1] = v % 31 - 1; v /= 31;
		pos[0][0] = v % 31 - 1; v /= 31;
		idx = v;
	}

	inline unsigned int hash()
	{
		unsigned int ret = idx;
		ret *= 31; ret += pos[0][0] + 1;
		ret *= 31; ret += pos[0][1] + 1;
		ret *= 31; ret += pos[1][0] + 1;
		ret *= 31; ret += pos[1][1] + 1;
		ret *= 2; ret += turn;
		return ret;
	}

	bool advance(int item, int steps)
	{
		idx++;

		int (&me)[2] = pos[turn];
		int (&opp)[2] = pos[!turn];

		bool paired = false;

		if (me[item] == FINISHED)
			return false;
		if (me[item] == me[!item] && me[item] != NOT_STARTED)
			paired = true;

		int next_pos;
		if (me[item] == NOT_STARTED)
			next_pos = steps;
		else if (me[item] == 0)
			next_pos = FINISHED;
		else if (me[item] == 25)
		{
			const int v[5] = {26, 22, 27, 28, 0};
			next_pos = v[steps - 1];
		}
		else if (me[item] == 26)
		{
			const int v[5] = {22, 27, 28, 0, FINISHED};
			next_pos = v[steps - 1];
		}
		else if (me[item] == 27)
		{
			const int v[5] = {28, 0, FINISHED, FINISHED, FINISHED};
			next_pos = v[steps - 1];
		}
		else if (me[item] == 28)
		{
			const int v[5] = {0, FINISHED, FINISHED, FINISHED, FINISHED};
			next_pos = v[steps - 1];
		}
		else if (me[item] == 5)
		{
			const int v[5] = {20, 21, 22, 23, 24};
			next_pos = v[steps - 1];
		}
		else if (me[item] == 10)
		{
			const int v[5] = {25, 26, 22, 27, 28};
			next_pos = v[steps - 1];
		}
		else if (me[item] <= 14)
			next_pos = me[item] + steps;
		else if (me[item] <= 19)
		{
			next_pos = me[item] + steps;
			if (next_pos == 20)
				next_pos = 0;
			else if (next_pos > 20)
				next_pos = FINISHED;
		}
		else if (me[item] == 22)
		{
			next_pos = 26 + steps;
			if (next_pos == 29)
				next_pos = 0;
			else if (next_pos > 29)
				next_pos = FINISHED;
		}
		else if (me[item] <= 24)
		{
			next_pos = me[item] + steps;
			if (next_pos >= 25)
				next_pos = (next_pos - 25) + 15;
		}

		me[item] = next_pos;
		if (paired)
			me[!item] = next_pos;

		if (me[item] == FINISHED)
		{
			turn = !turn;
			return true;
		}

		bool once_more = (steps >= 4);
		if (opp[0] == me[item])
			once_more = true, opp[0] = NOT_STARTED;
		if (opp[1] == me[item])
			once_more = true, opp[1] = NOT_STARTED;

		if (!once_more)
			turn = !turn;
		return true;
	}

	void normalize()
	{
		if (pos[0][0] > pos[0][1])
			swap(pos[0][0], pos[0][1]);
		if (pos[1][0] > pos[1][1])
			swap(pos[1][0], pos[1][1]);

		if (pos[0][0] == FINISHED && pos[0][1] == FINISHED && turn == 0)
			turn = 1;
		else if (pos[1][0] == FINISHED && pos[1][1] == FINISHED && turn == 1)
			turn = 0;
	}
};

const int STATES = 94199142;

unsigned int did[(STATES + 31) / 32];

void set_did(unsigned int h)
{ did[h / 32] |= (1u << (h % 32)); }

bool get_did(unsigned int h)
{ return !!(did[h / 32] & (1u << (h % 32))); } 

queue<int> que;

inline void push(state_s &state)
{
	state.normalize();
	int hv = state.hash();
	if (get_did(hv))
		return;
	set_did(hv);
	que.push(hv);
}

int data[51];
int N;
int U;
int A, B;

int main()
{
	int tc;
	scanf("%d", &tc);

	for (int ti = 1;ti <= tc;ti++)
	{
		vector<int> a_target, b_target;

		memset(did, 0, sizeof(did));
		scanf("%d %d %d %d", &U, &N, &A, &B);
		for (int i = 0;i < N;i++)
		{
			char buf[64];
			scanf("%s", buf);
			string str(buf);
			if (str == "Do") data[i] = 1;
			if (str == "Gae") data[i] = 2;
			if (str == "Gul") data[i] = 3;
			if (str == "Yut") data[i] = 4;
			if (str == "Mo") data[i] = 5;
		}

		for (int i = 0;i < A;i++)
		{
			int v;
			scanf("%d", &v);
			a_target.push_back(v);
		}

		for (int i = 0;i < B;i++)
		{
			int v;
			scanf("%d", &v);
			b_target.push_back(v);
		}

		sort(a_target.begin(), a_target.end());
		sort(b_target.begin(), b_target.end());

		state_s initial(0);
		initial.idx = 0;
		initial.turn = 0;
		initial.pos[0][0] = (U >= 1 ? NOT_STARTED : FINISHED);
		initial.pos[0][1] = (U >= 2 ? NOT_STARTED : FINISHED);
		initial.pos[1][0] = (U >= 1 ? NOT_STARTED : FINISHED);
		initial.pos[1][1] = (U >= 2 ? NOT_STARTED : FINISHED);

		que = queue<int>();
		push(initial);

		bool found_answer = false;
		for (;!que.empty();)
		{
			int curv = que.front(); que.pop();
			state_s cur(curv);
			if (cur.idx == N)
			{
				vector<int> a_pos;
				vector<int> b_pos;

				if (0 <= cur.pos[0][0] && cur.pos[0][0] < FINISHED)
					a_pos.push_back(cur.pos[0][0]);
				if (0 <= cur.pos[0][1] && cur.pos[0][1] < FINISHED)
					a_pos.push_back(cur.pos[0][1]);

				if (0 <= cur.pos[1][0] && cur.pos[1][0] < FINISHED)
					b_pos.push_back(cur.pos[1][0]);
				if (0 <= cur.pos[1][1] && cur.pos[1][1] < FINISHED)
					b_pos.push_back(cur.pos[1][1]);

				sort(a_pos.begin(), a_pos.end());
				sort(b_pos.begin(), b_pos.end());

				if (a_pos == a_target && b_pos == b_target)
				{
					found_answer = true;
					break;
				}

				continue;
			}

			int v = data[cur.idx];

			{
				state_s next = cur;
				if (next.advance(0, v))
					push(next);
			}

			{
				state_s next = cur;
				if (next.advance(1, v))
					push(next);
			}
		}

		printf("Case #%d: %s\n", ti, found_answer ? "YES" : "NO");
	}

	return 0;
}


