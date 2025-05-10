
def is_bulky(length: int, width: int, height: int) -> bool:
    BULK_D_THRESHOLD = 10000
    BULK_V_THRESHOLD = 1000000000
    volume = length * width * height
    print(volume)
    return length >= BULK_D_THRESHOLD or width >= BULK_D_THRESHOLD or height >= BULK_D_THRESHOLD or volume >= BULK_V_THRESHOLD

def is_heavy(mass: int) -> bool:
    HEAVY_THRESHOLD = 100
    return mass >= HEAVY_THRESHOLD

def solution(length: int, width: int, height: int, mass: int) -> str:
    if is_bulky(length, width, height) and is_heavy(mass):
        return "Both"
    elif is_bulky(length, width, height):
        return "Bulky"
    elif is_heavy(mass):
        return "Heavy"
    else:
        return "Neither"

if __name__ == '__main__':
    '''
    Note: 
        that the volume of the box is the product of its length, width and height.
        
    Constraints:
        1 <= length, width, height <= 10^5
        1 <= mass <= 10^3
    '''
    input1_length, input1_width, input1_height, input1_mass = 1000, 35, 700, 300
    print(solution(input1_length, input1_width, input1_height, input1_mass))
    print(solution(input1_length, input1_width, input1_height, input1_mass) == "Heavy")

    input2_length, input2_width, input2_height, input2_mass = 200, 50, 800, 50
    print(solution(input2_length, input2_width, input2_height, input2_mass))
    print(solution(input2_length, input2_width, input2_height, input2_mass) == "Neither")

    input3_length, input3_width, input3_height, input3_mass = 1569, 714, 170, 408
    print(solution(input3_length, input3_width, input3_height, input3_mass))
    print(solution(input3_length, input3_width, input3_height, input3_mass) == "Heavy")