#-*-coding:utf-8-*-
from tkinter import *

def enter(label):
    if label == 'C':
        entry.delete(0,END)
    elif label == '=':
        ans = eval(entry.get())
        entry.delete(0, END)
        entry.insert(0, ans)
    else:
        entry.insert(END, label)

def mkBtn(frm, numstr):
    for label in numstr:
        numBtn = Button(frm, text=label, width=3, command=(lambda char=label: enter(char)))
        numBtn.pack()


def main():
    calWin = Tk()
    calWin.title('사칙연산_계산기')
    global entry
    entry = Entry(calWin, width=12, justify=RIGHT)
    entry.pack()
    Button = ['7410', '852=', '963+', 'C/*-']
    for set in Button:
        frm = Frame(calWin)
        frm.pack(side=LEFT)
        mkBtn(frm, set)
    calWin.mainloop()


if __name__ == '__main__':
    main()