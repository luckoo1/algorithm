from collections import deque

def  print_lst(gr):
    print()
    for i in range(len(gr)):
        for j in range(len(gr[i])):
            for l in range(len(gr[i][j])):
                print(dist[i][j][l],end = ' ')
            print()
        print()
        
K = int(input())
COL,ROW = map(int,input().split())
graph = []
for _ in range(ROW):
    graph.append(list(map(int,input().split())))
dist = [[[0]*COL for _ in range(ROW)] for _ in range(K+1)]
dr = [1,-1,0,0]
dc = [0,0,1,-1]
hr = [-2,-2,-1,1,2, 2, 1,-1]
hc = [-1, 1, 2,2,1,-1,-2,-2]
flag = 0
q = deque()
q.append((0,0,0))

ans = 0
while(len(q)!=0):
    h,r,c = q.popleft()
    if ((r == ROW-1) and (c == COL-1)):
        ans = dist[h][r][c]
        flag = 1
        break

    for i in range(4):
        nr = r+dr[i]
        nc = c+dc[i]
        if(nr<0 or nc<0 or nr>=ROW or nc>= COL):
            continue
        if(dist[h][nr][nc] != 0 or graph[nr][nc] == 1):
            continue
        q.append([h,nr,nc])
        dist[h][nr][nc] = dist[h][r][c] + 1

    if(h < K):
        for i in range(8):
            nr = r + hr[i]
            nc = c + hc[i]
            if(nr<0 or nc<0 or nr >= ROW or nc>= COL):
                continue
            if(dist[h+1][nr][nc] != 0 or graph[nr][nc] == 1):
                continue
            q.append([h+1,nr,nc])
            dist[h+1][nr][nc]= dist[h][r][c] + 1

# print_lst(dist)
if (flag == 0):
    ans = -1
print(ans)