import sys
sys.stdin = open("input.txt","rt")
row,column = map(int,input().split())


arr = [[0 for j in range(column)]for i in range(row)]

for i in range(row):
    temp = list(map(int,input().split()))
    for j in range(column):
        arr[i][j] = temp[j]

f_row,f_column = map(int,input().split())

max = 0
sum = 0
pos_row = 0
pos_column = 0


while(pos_row<row-f_row):
    sum = 0
    for i in range(pos_row,pos_row + f_row,+1):
        for j in range(pos_column,pos_column + f_column):
            sum =sum + arr[i][j]

    if(sum > max):max = sum
    pos_column = pos_column+1
    if(pos_column > column-f_column):
        pos_column = 0
        pos_row = pos_row +1

    
print(max)

