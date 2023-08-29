t=int(input())
finalans=[]
for i in range(t):
    n=int(input())
    lstin=list(map(int,input().split()))
    a=int(input())
    a=a-1
    b=lstin[a]
    lstin.sort()
    ans=lstin.index(b)+1
    finalans.append(ans)
for j in finalans:
    print(j)
