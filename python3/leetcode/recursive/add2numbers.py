from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self):
        return f"ListNode{{val: {self.val}, next: {self.next}}}"

def list_to_linked_list(lst):
    if not lst:
        return None
    head = ListNode(lst[0])
    current = head
    for value in lst[1:]:
        current.next = ListNode(value)
        current = current.next
    return head

def add_two_numbers(l1: Optional[ListNode], l2: Optional[ListNode], carry=0) -> Optional[ListNode]:
    if not l1 and not l2 and not carry:
        return None

    val1 = l1.val if l1 else 0
    val2 = l2.val if l2 else 0
    total = val1 + val2 + carry
    carry = total // 10
    new_node = ListNode(total % 10)
    new_node.next = add_two_numbers(l1.next if l1 else None, l2.next if l2 else None, carry)
    return new_node

def solution(l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
    return add_two_numbers(l1, l2)



if __name__ == '__main__':
    input1_1, input1_2 = list_to_linked_list([2,4,3]), list_to_linked_list([5,6,4])
    print(solution(input1_1, input1_2))  # Expected output: [7,0,8]
    print(solution(input1_1, input1_2) == [7,0,8])  # Expected output: True