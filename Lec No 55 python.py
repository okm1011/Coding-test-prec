import sys
sys.stdin = open("input.txt","rt")
n = int(input())
def rec(x):
    if(x==0):
        return
    else:
        rec(x-1)
        print(x," ")
        
rec(n)