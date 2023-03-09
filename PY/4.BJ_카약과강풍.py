N, S, R = list(map(int, input().split()))
no_lst = list(map(int, input().split()))
yes_lst = list(map(int, input().split()))

check = [1]*(N+2)

for i in no_lst:
    check[i] -= 1

for i in yes_lst:
    check[i] += 1

for i in range(1, N+1):
    if (check[i-1] == 0 and check[i] == 2):
        check[i] =1
        check[i-1] = 1
    elif (check[i+1] == 0 and check[i] == 2):
        check[i] =1
        check[i+1] = 1

ans = 0
for i in range(1, N+1):
    if(check[i]==0):
        ans+=1
        
print(ans)