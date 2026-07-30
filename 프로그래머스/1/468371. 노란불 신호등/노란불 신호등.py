from math import lcm

def solution(signals):
    # 각 신호등의 한 사이클 길이
    periods = [g + y + r for g, y, r in signals]

    # 전체 상태가 반복되는 주기 = 탐색 상한
    limit = lcm(*periods)

    for t in range(1, limit + 1):
        all_yellow = True
        
        for i in range(len(signals)):
            g, y, r = signals[i]
            pos = (t - 1) % periods[i]      # 사이클 안에서의 위치
            
            if not (g <= pos < g + y):      # 노란불 구간이 아니면
                all_yellow = False
                break
                
        if all_yellow:
            return t

    return -1