#include <stdio.h>
#include <map>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector < vector< int > > G;
map<string, int> TABLE;
map<int, int> path;

void init() 
{
  TABLE["Do"] = 1;
  TABLE["Gae"] = 2;
  TABLE["Gul"] = 3;
  TABLE["Yut"] = 4;
  TABLE["Mo"] = 5;

  G.resize(30);
  for (int i=0; i<19; i++)
    G[i].push_back(i+1);

  for (int i=20; i<24; i++)
    G[i].push_back(i+1);

  for (int i=25; i<28; i++)
    G[i].push_back(i+1);

  G[0].push_back(29);
  G[5].push_back(20);
  G[10].push_back(25);
  G[22].push_back(27);
  G[24].push_back(15);

  G[28].push_back(0);
  G[19].push_back(0);

  path[5] = -1;
  path[10] = -1;
  path[22] = -1;
}


int main()
{
  //FILE *fp = fopen("B-small-attempt1.in", "r");
  //FILE *fout = fopen("output.txt", "w");
  FILE *fp = stdin;
  FILE *fout = stdout;

  init();
  
  int T;
  fscanf(fp, "%d", &T);
  for (int w=0; w<T; w++) {
    int U, N, A, B;

    fscanf(fp, "%d %d %d %d", &U, &N, &A, &B);

    int turn = 0;
    bool state[2] = {false, false};
    int cur[2] = {29, 29};
    for (int i=0; i<N; i++) {
      char temp[10];

      fscanf(fp, "%s", temp);
      int res = TABLE[temp];

      if (cur[turn] == 29)
        cur[turn] = 0;

      if (cur[turn] == 0 && state[turn] == true) {
        //game end
        cur[turn] = 29;
        break;
      }
      
      state[turn] = true;
      if (path.find(cur[turn]) != path.end()) {
        cur[turn] = G[cur[turn]][1];
        res--;
      }
      else {
        cur[turn] = G[cur[turn]][0];
        res--;
      }

      for (int k=1; k<=res; k++) {
        if (cur[turn] == 0 && state[turn] == true) {
          //game end
          cur[turn] = 29;
          break;
        }
  
        cur[turn] = G[cur[turn]][0];
      }

      if (cur[turn] == 29)
        break;
      

      if (cur[0] == cur[1]) {
        if (turn == 0) {
          cur[1] = 29;
          state[1] = false;
        }
        else {
          cur[0] = 29;
          state[0] = false;
        }
      }
      else if (strcmp(temp, "Yut") == 0 || strcmp(temp, "Mo") == 0) {

      }
      else {
        if (turn == 0) turn = 1; else turn = 0;
      }

    }
    char temp[1000];
    fgets(temp, 1000, fp);

    int last[2];
    if (A == 0)
      last[0] = 29;
    else
      fscanf(fp, "%d", &last[0]);

    if (B == 0)
      last[1] = 29;
    else
      fscanf(fp, "%d", &last[1]);

    if (temp[0] != '\n') {
      fprintf(fout, "Case #%d: NO\n", w+1);
      continue;
    }

    if (cur[0] == last[0] && cur[1] == last[1])
      fprintf(fout, "Case #%d: YES\n", w+1);
    else
      fprintf(fout, "Case #%d: NO\n", w+1);
  }


  return 0;
}

