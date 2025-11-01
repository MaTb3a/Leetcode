# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        mp = Counter(nums)
        top = None
        while head:
            if head.val not in mp:
                tmp = ListNode(head.val,top)
                top = tmp
            head = head.next
        rev = None
        while top:
            tmp = ListNode(top.val,rev)
            rev = tmp
            top = top.next
        return tmp
