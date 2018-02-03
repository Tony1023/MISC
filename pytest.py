def shift(lst,k):
    lst2 = lst[:k]
    for i in range(k,len(lst)):
        lst[i - k] = lst[i]
    for i in range(0,k):
        lst[i + k] = lst2[i]

lst = [1,2,3,10,11,12]
shift(lst,3)
print(lst)