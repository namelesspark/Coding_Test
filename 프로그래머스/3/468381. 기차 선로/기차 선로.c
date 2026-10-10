#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int** grid, size_t grid_rows, size_t grid_cols) {
    int n = grid_rows, m = grid_cols, answer = 0;
    int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
    int rail[] = {0, 10, 5, 15, 9, 3, 6, 12};

    typedef struct {
        int r, c, d;
        int board[20], visit[20];
    } State;

    State stack[128], start = {0};
    int top = 0;

    for (int i = 0; i < n * m; i++)
        start.board[i] = grid[i / m][i % m];

    start.d = 1;
    stack[top++] = start;

    while (top) {
        State s = stack[--top];
        int r = s.r, c = s.c, d = s.d;

        if (r < 0 || r >= n || c < 0 || c >= m)
            continue;

        int p = r * m + c;

        for (int t = 1; t <= 7; t++) {
            if (s.board[p] && s.board[p] != t)
                continue;

            int entry = 1 << ((d + 2) % 4);
            int bit = t == 3 ? (d % 2 ? 1 : 2) : 1;

            if (!(rail[t] & entry) || (s.visit[p] & bit))
                continue;

            if (t == 3 && (r == 0 || r == n - 1 ||
                           c == 0 || c == m - 1))
                continue;

            State next = s;
            next.board[p] = t;
            next.visit[p] |= bit;

            if (p == n * m - 1) {
                bool ok = true;
                for (int i = 0; i < n * m; i++)
                    if (next.board[i] > 0 &&
                        next.visit[i] != (next.board[i] == 3 ? 3 : 1))
                        ok = false;

                answer += ok;
                continue;
            }

            int out = d;
            if (t != 3)
                for (out = 0; !(rail[t] & ~entry & (1 << out)); out++);

            next.r += dr[out];
            next.c += dc[out];
            next.d = out;
            stack[top++] = next;
        }
    }

    return answer;
}