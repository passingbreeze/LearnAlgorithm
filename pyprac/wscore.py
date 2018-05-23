from functools import reduce

print(reduce(lambda x,y:x+y, [ord(n.upper()) for n in list(input().replace(" ",""))]))
