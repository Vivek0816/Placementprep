#from functools import reduce
#print("Python Works!")
#nums=[x for x in range(10)]
#print(f"nums list is {nums}")
#increment=list(map(lambda a:a+2, nums))
#print(f"increment list is {increment}")
#evens=list(filter(lambda a:a%2==0,nums))
#print(f"evens list is {evens}")
#odds=list(filter(lambda a:a%2!=0,nums))
#print(f"odds list is {odds}")
#sum=reduce(lambda a,b:a+b,nums)
#print(sum)

freq={}
max=0
numslist=[1,2,2,3,3,3,5,5,5,5,5]
for i in numslist:
    if i in freq:
        freq[i]=freq[i]+1
        if(freq[i]>max):
            max=freq[i]
            max_element=i
    else:
        freq[i]=1
print(freq)
print(max_element,max)