N, S, R = list(map(int, input().split()))
no_list = list(map(int, input().split()))
yes_list = list(map(int, input().split()))
check = [1]*(12)

del_list = []
for i in no_list:
    check[i] = 0

for i in yes_list:
    if(check[i] == 0):
        check[i] = 1
        del_list.append(i)

yes_list = [i for i in yes_list if i not in del_list]

ans = 999

def dfs(dep):
    global N, S, R, yes_list, check, ans
    if(dep == len(yes_list)):
        temp_ans = check.count(0)
        ans = min(ans,temp_ans)
        return

    for idx in yes_list:
        if(check[idx+1] == 0):
            check[idx+1] = 1
            dfs(dep+1)
            check[idx+1] = 0
        if(check[idx-1] == 0):
            check[idx-1] = 1
            dfs(dep+1)
            check[idx-1] = 0
        dfs(dep+1)

if(len(yes_list)==0):
    ans = check.count(0)
else : 
    dfs(0)
print(ans)