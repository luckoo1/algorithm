from collections import deque

#init
ROW,COL = list(map(int,input().split()))
graph=[]
for _ in range(ROW):
    graph.append(list(map(int,input().split())))
check = [[False]*COL for _ in range(ROW)]
dr = [1,-1,0,0]
dc = [0,0,-1,1]

q = deque()
ans = 0

def bfs(r,c):
    temp_ans = 0
    q.append([r,c])
    check[r][c] = True

    while(len(q)!=0):
        now_r,now_c = q.popleft()
        temp_ans += 1
        for i in range(4):
            move_r = now_r + dr[i]
            move_c = now_c + dc[i]
            if(move_r<0 or move_c<0 or move_r>=ROW or move_c>=COL):
                continue
            if(check[move_r][move_c]==True or graph[move_r][move_c]==0):
                continue
            q.append([move_r,move_c])
            check[move_r][move_c]=True
    
    if(temp_ans>ans):
        ans = temp_ans

how_many = 0

for i in range(ROW):
    for j in range(COL):
        if(graph[i][j]==1 and check[i][j]==False):
            bfs(i,j)
            how_many+=1

print(how_many)
print(ans)




