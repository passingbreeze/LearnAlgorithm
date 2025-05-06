from typing import *


def solution(keyinput: List[str], board: List[int]) -> List[int]:
    x, y = 0, 0
    max_x, max_y = board[0] // 2, board[1] // 2
    for k in keyinput:
        if k == "up":
            y += 1
        elif k == "down":
            y -= 1
        elif k == "left":
            x -= 1
        elif k == "right":
            x += 1

        # Check boundaries
        x = max(-max_x, min(x, max_x))
        y = max(-max_y, min(y, max_y))

    return [x, y]


if __name__ == '__main__':
    keyinput1, boardinput1 = ["left", "right", "up", "right", "right"],	[11, 11]
    print(solution(keyinput1, boardinput1))
    print(solution(keyinput1, boardinput1) == [2, 1])

    keyinput2, boardinput2 = ["down", "down", "down", "down", "down"], [7, 9]
    print(solution(keyinput2, boardinput2))
    print(solution(keyinput2, boardinput2) == [0, -4])
