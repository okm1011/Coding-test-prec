import sys

sys.stdin = open("input.txt","rt")

n = int(input())

 
arr=[]
arr.append(1)
p2=0
p3=0
p5 = 0
min_val = 0

for i in range(1,n,1):
    arr_value = [arr[p2]*2,arr[p3]*3,arr[p5]*5]
    min_val = min(arr_value)
    arr.append(min_val)
    if(min_val == arr[p2]*2):
        p2=p2+1
    if(min_val == arr[p3]*3):
        p3=p3+1
    if(min_val == arr[p5]*5):
        p5=p5+1


print(arr[n-1])