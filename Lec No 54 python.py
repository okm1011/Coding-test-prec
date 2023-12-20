import sys

sys.stdin = open("input.txt","rt")
n = int(input())
input = list(map(int,input().split()))
stack = []
answer = []
flag = 0
cnt = 1
i = 0
stack.append(input[i])
answer.append('P')


while(cnt<=n):
    print(cnt,i)
    if (stack):

        if(stack[-1] == cnt):
            stack.pop();
            cnt = cnt +1
            answer.append('O')
            continue

    i = i +1
    if(i>=n):
        flag = 1
        break
    stack.append(input[i])
    answer.append('P')
if(flag):
    print("impossible")
else:
    
    while(answer):
        print(answer.pop(0))
        
