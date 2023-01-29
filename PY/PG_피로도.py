ans = 0
check = [False for _ in range(8)]

def dfs(dep, k, lst, temp_ans):
    global check
    global ans
    if(dep == len(lst)):
        if(ans < temp_ans):
            ans = temp_ans
        return

    for i in range(len(lst)):
        if(check[i] == False):
            check[i] = True

            if(lst[i][0] <= k):
                dfs(dep+1, k-lst[i][1], lst, temp_ans+1)
            else:
                dfs(dep+1, k, lst, temp_ans)

            check[i] = False


def solution(k, dungeons):
    dfs(0, k, dungeons, 0)
    global ans
    return ans

ans = solution(80, [[80, 20], [50, 40], [30, 10]])
print(ans)
