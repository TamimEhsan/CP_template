#include<bits/stdc++.h>
using namespace std;


#define inf 1010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define swap(x, y) (x ^= y, y ^= x, x ^= y)
#define F(i, j) (abs(((ar[i][j] - 1) >> 2) - i) + abs( ((ar[i][j] - 1) & 3) - j))

bool flag;
char str[60];
char dir[] = "LRUD";
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int len[4] = {0}, idx[4][4], ar[4][4], transpose[4][4];

int row_conflict(int rc){
    int i, j, k, x, y, res = 0;

    for (i = 0; i < 4; i++){
        x = (ar[rc][i] >> 2);
        if (ar[rc][i] != 16) idx[x][len[x]++] = ar[rc][i];
    }

    for (i = 0; i < 4; i++){
        if (len[i] > 1){
            for (j = 0; j < len[i]; j++){
                for (k = j + 1; k < len[i]; k++){
                    if (idx[i][j] > idx[i][k]) res += 2;
                }
            }
        }
        len[i] = 0;
    }
    return res;
}

int column_conflict(int rc){
    int i, j, k, x, y, res = 0;

    for (i = 0; i < 4; i++){
        x = (ar[i][rc] & 3);
        if (ar[i][rc] != 16) idx[x][len[x]++] = ar[i][rc];
    }

    for (i = 0; i < 4; i++){
        if (len[i] > 1){
            for (j = 0; j < len[i]; j++){
                for (k = j + 1; k < len[i]; k++){
                    if (idx[i][j] > idx[i][k]) res += 2;
                }
            }
        }
        len[i] = 0;
    }
    return res;
}


int heuristic(int bx, int by){
    int i, j, k, l, res, linear_conflict = 0, manhattan_distance = 0;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            transpose[j][i] = ar[i][j];
            if (ar[i][j] != 16){
                manhattan_distance += F(i, j);
            }
        }
        linear_conflict += row_conflict(i);
        linear_conflict += column_conflict(i);
    }

    res = manhattan_distance + linear_conflict;
    return res;
}

int ida(int bx, int by, int lx, int ly, int g, int lim, int d, int h){
    if (flag) return 0;

    if (!h){
        if (!flag){
            flag = true;
            str[d] = 0;
            puts(str);
        }
        return g;
    }

    int f = g + h;
    if (f > lim) return f;

    int i, k, l, nh, r, res = inf;
    for (i = 0; i < 4; i++){
        k = bx + dx[i], l = by + dy[i];
        if (k >= 0 && k < 4 && l >= 0 && l < 4 && !(k == lx && l == ly)){
            nh = h;
            nh -= F(k, l);
            if (bx != k) nh -= row_conflict(bx), nh -= row_conflict(k);
            if (by != l) nh -= column_conflict(by), nh -= column_conflict(l);
            swap(ar[bx][by], ar[k][l]);

            nh += F(bx, by);
            if (bx != k) nh += row_conflict(bx), nh += row_conflict(k);
            if (by != l) nh += column_conflict(by), nh += column_conflict(l);

            str[d] = dir[i];
            r = ida(k, l, bx, by, g + 1, lim, d + 1, nh);
            swap(ar[bx][by], ar[k][l]);
            if (r < res) res = r;
            if (r <= lim) return r;
        }
    }

    return res;
}

int Solve(int bx, int by){
    int res, lim = heuristic(bx, by);

    flag = false;
    for (; ;){
        res = ida(bx, by, bx, by, 0, lim, 0, heuristic(bx, by));
        if (res <= lim) return res;
        else lim = res;
    }
}

bool Solvable(int bx, int by){
    int i, j, r = 0, counter = 0;

    for (i = 0; i < 16; i++){
        if (ar[i >> 2][i & 3] == 16) r = (i >> 2);
        else{
            for (j = i + 1; j < 16; j++){
                if (ar[j >> 2][j & 3] < ar[i >> 2][i & 3]) counter++;
            }
        }
    }

    return ((counter + r) & 1);
}

void solve(){
    int  i, j, k, bx, by;
    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            scanf("%d", &ar[i][j]);
            if (!ar[i][j]){
                bx = i, by = j;
                ar[i][j] = 16;
            }
        }
    }

    if (!Solvable(bx, by)) puts("This puzzle is not solvable.");
    else{
        int res = Solve(bx, by);
        if (res > 35) puts("This puzzle is not solvable.");
    }


}

int main(){
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){

        printf("Case %d: ",t);
        solve();
    }
}

