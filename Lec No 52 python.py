import sys
global top
top = -1

def pop():
    global top
    return stack[top]
def push(x):
    global top
    top+=1 
    stack.append(x)


sys.stdin = open("input.txt","rt")
n,k = map(int,input().split())
top = -1
stack=[]
str = "0123456789ABCDEF"

while(n>0):
    push(n%k)
    n = int(n/k)
while(top!=-1):
    a = pop()
    print(str[a])
    top-=1


