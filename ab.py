arr = [1,5,3,2,1]
brr = [1,3,5,2,1]
count = 0
for i in range(5):
        if arr[i] == brr[i]:
                count += 1
        else:
                print("NOT PERFECT")
                break
if count == 5:
        print("PERFECT")
