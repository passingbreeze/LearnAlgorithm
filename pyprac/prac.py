#-*-coding:utf-8-*-
import sys;input()
def main():

    for l in sys.stdin:
        print (sum(map(int, l.split())))

if __name__ == '__main__':
    main()