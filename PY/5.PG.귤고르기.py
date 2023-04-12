def solution(k, tangerine):
    unique_lst = list(set(tangerine))
    hash_dict = dict()
    for i in unique_lst:
        hash_dict[i]=0
    for i in tangerine:
        hash_dict[i]+=1

    hash_dict = dict(sorted(hash_dict.items(),key = lambda x:x[1],reverse= True))
    total = 0
    answer = 0
    for key,value in hash_dict.items():
        total += value
        answer += 1
        if(total>=k):
            break
    return answer