from cs50 import get_int

cities = get_int("")
c1p, c1d = input("").split()
c2p, c2d = input("").split()
qq = c1p + c1d
ww = c2p + c2d
print(qq)
print(ww)
if c1p + c1d == c2p and c2p + c2d == c1p:
    print("YES")
else:
    print("NO")
