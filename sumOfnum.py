#code
t = int(input())
while(t > 0):
    x, y = input().split()
    # y = int(input())
    l = len(str(x))
    x = int(x)
    y = int(y)
    sum = x+y
    sum = str(sum)
    if(l != len(sum)):
        print(x)
    else:
        print(sum)
    t -= 1
    