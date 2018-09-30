#code
t = 0
t = int(input())
while(t > 0):
    x = 0
    x = int(input())
    l = x % 10
    if (l <= 5):
        while(x % 10 != 0):
            x -= 1
    else:
        while(x % 10 != 0):
            x += 1
    print(x)
    t -= 1