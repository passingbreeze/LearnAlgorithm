#-*-coding:utf-8-*-

string = []

while True:
    input_str = input()
    if input_str == "":
        break
    else:
        string.append(input_str)

for line in string:
    print(line)