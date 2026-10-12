#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int dist_limit, int split_limit) {
    long long D = dist_limit, S = split_limit, best = 1;
    for (long long p2 = 1, a = 0; p2 <= S; p2 *= 2, a++)        // 위쪽 2분기 레벨 a개
        for (long long p3 = 1, F = 0; p2 * p3 <= S; F += p3, p3 *= 3) {  // 아래쪽 3분기 c개, F=(3^c-1)/2
            long long top = a ? 1LL << (a - 1) : 0, lo = 1, hi = top, ys = top;
            while (lo <= hi) {                                   // 최적 y(=마지막 2분기 레벨 노드 수) 탐색
                long long m = (lo + hi) / 2, s = 0, t = m;
                for (long long i = 0; i < a; i++) s += t, t = (t + 1) / 2;
                if (s + 2 * m * F >= D) ys = m, hi = m - 1; else lo = m + 1;
            }
            for (long long y = ys; y >= ys - 1 && y >= 0; y--) {
                long long c = 0, t = y;                          // c = y개를 떠받치는 최소 비용
                for (long long i = 0; i < a; i++) c += t, t = (t + 1) / 2;
                if (c > D) continue;
                long long V = (a ? 2 * y : 1) * F, hu = a ? top - 1 + y : 0;
                if (hu > D) hu = D;
                long long u = D - V < c ? c : (D - V > hu ? hu : D - V);
                long long v = D - u < V ? D - u : V;
                if (1 + u + 2 * v > best) best = 1 + u + 2 * v;
            }
        }
    return (int)best;
}