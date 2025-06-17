# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        fast,slow = head,head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        rev = None
        while slow:
            nxt = ListNode(slow.val,rev)
            rev = nxt
            slow = slow.next
        
        while head and rev:
            if head.val != rev.val:
                return False
            head = head.next
            rev = rev.next
        return True