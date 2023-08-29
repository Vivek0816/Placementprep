t=int(input())
finalans=[]
for i in range(t):
    n=int(input())
    lstin=list(map(int,input().split()))
    a=int(input())
    b=lstin.index[a-1]
    lstin.sort()
    ans=lstin.index(a)
    finalans.append(ans)
for j in finalans:
    print(j)
