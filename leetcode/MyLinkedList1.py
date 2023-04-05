class MyLinkedList:

    def __init__(self):
        self.head = None

    def get(self, index: int) -> int:
        if self.head is None or index < 0:
            return -1
        node = self.head
        for _ in range(index):
            if node.next_node is None:
                return -1
            else:
                node = node.next_node
        return node.val

    def addAtHead(self, val: int) -> None:
        self.head = Node(val, self.head)

    def addAtTail(self, val: int) -> None:
        if self.head is None:
            self.head = Node(val, None)
        else:
            node = self.head
            while node.next_node:
                node = node.next_node
            node.next_node = Node(val, None)

    def addAtIndex(self, index: int, val: int) -> None:
        if not index:
            self.head = Node(val, self.head)
        else:
            node = self.head
            for _ in range(index - 1):
                node = node.next_node
                if node is None:
                    return
            if node is None:
                    return
            node.next_node = Node(val, node.next_node)
                    

    def deleteAtIndex(self, index: int) -> None:
        if not index:
            self.head = self.head.next_node
        else:
            node = self.head
            for _ in range(index - 1):
                node = node.next_node
                if node is None or node.next_node is None:
                    return
            if node is None or node.next_node is None:
                    return
            node.next_node = node.next_node.next_node


        
class Node:
    def __init__(self, val: int=None, next_node=None):
        self.val = val
        self.next_node = next_node
