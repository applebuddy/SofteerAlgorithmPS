//
//  장애물인식프로그램_409.cpp
//  SofteerAlgorithmPS
//
//  Created by MinKyeongTae on 2021/10/26.
//

#if 0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, ans=0;
vector<vector<int>> G;
vector<vector<bool>> chk;
vector<int> ansList;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int cnt=0;

void DFS(int x, int y) {
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || ny<0 || nx>=N || ny>=N || G[nx][ny]==0) continue;
        if(chk[nx][ny]) continue;
        chk[nx][ny]=true;
        cnt++;
        DFS(nx, ny);
    }
}

int main() {
    cin>>N;
    G = vector<vector<int>>(N, vector<int>(N, 0));
    chk = vector<vector<bool>>(N, vector<bool>(N, false));

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) scanf("%01d", &G[i][j]);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) {
            if(chk[i][j] || G[i][j]==0) continue;
            chk[i][j]=true;
            cnt=1;
            DFS(i, j);
            ansList.push_back(cnt);
        }
    
    sort(ansList.begin(), ansList.end());
    printf("%d\n", (int)ansList.size());
    for(auto &v: ansList) printf("%d\n", v);
}

#endif
