a = [1,5,2,6,8,3,7,9,10]
j = 1
n = len(a)
for i in range(round(n/2)):
    tmp = a[i]
    a[i] = a[n-j]
    a[n-j] = tmp
    j = j + 1
print(a)



































