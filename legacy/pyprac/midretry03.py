#-*-coding:utf-8-*-

def bmi(w, h):
    bmi = (w/(h**2))*10000.0
    if bmi<15.0 :
        str = "VSU"
    elif bmi<16.0:
        str = "SUN"
    elif bmi<18.5:
        str = "UND"
    elif bmi<25.0:
        str = "NOR"
    elif bmi<30.0:
        str = "OVE"
    elif bmi<35.0:
        str = "MOV"
    elif bmi<40.0:
        str = "SOV"
    else:
        str = "VSO"
    return str

def main():
    weight = float(input())
    height = float(input())
    print(bmi(weight, height))

if __name__ == '__main__':
    main()