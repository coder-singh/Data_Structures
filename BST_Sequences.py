import copy

def remove_indexes(lst_with_index):
    lst = []
    for l in lst_with_index:
        lst.append(l[0])
    return lst

def place_num_in_lst(num, lst, start_idx):
    res = []
    for idx in range(start_idx+1, len(lst)+1):
        new_lst = copy.deepcopy(lst)
        new_lst.insert(idx, num)
        res.append((new_lst, idx))
    return res

def merge_list_with_lol(l1, l2):
    if l1 == [] or l2 == [[]]:
        if l1 != []:
            return l1
        if l2 != [[]]:
            return remove_indexes(l2)
        return [[]]
    for val in l1:
        temp_lst = []
        for lst,idx in l2:
            temp_lst += place_num_in_lst(val, lst, idx)
        l2 = temp_lst
    return remove_indexes(l2)

def merge(l1, l2, val):
    res = []
    for lst in l1:
        res.extend(merge_list_with_lol(lst, l2))
    for lst in res:
        lst.insert(0, val)
    return res

def find_sequences(root):
    if root is None:
        return [[]]
    left_sequences = find_sequences(root.left)
    right_sequences = find_sequences(root.right)
    for i in range(len(right_sequences)):
        right_sequences[i] = (right_sequences[i], -1)
    merged = merge(left_sequences, right_sequences, root.data)
    return merged

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

#          5
#         / \
#        2   6
#       / \
#      1   3
root = Node(5)
root.left = Node(2)
root.left.left = Node(1)
root.left.right = Node(3)
root.right = Node(6)

print(find_sequences(root))
