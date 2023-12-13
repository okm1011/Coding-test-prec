import sys


sys.stdin= open("input.txt","rt")

n=int(input())
arr = [[0 for j in range(n)] for i in range(n)]

input_line = list(map(int,input().split()))

for i in range(n):
    temp = input_line[i]
    for j in range(n):
        arr[j][i] = temp


input_line = list(map(int,input().split()))

for i in reversed(range(n)):
    max = input_line[(n-1)-i]
    
    
    for j in reversed(range(n)):
        
        if arr[i][j]>max:
            arr[i][j] = max
            

for i in range(n):
    for j in range(n):
        print(arr[i][j], end=" ")
    print()
