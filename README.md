### Getting all sequences that generate same BST

Solution:  
The idea is to solve this problem using divide & conquer approach. In this approach, we get sequences from left subtree and right subtree. Tricky part is to merge these sequences.  
ex: `[5]` , `[9, 8]`  should give `[[5, 9, 8], [9, 5, 8], [9, 8, 5]]` as result  
Now If the first list had one more number, say 4; then we had to start placing 4 at following positions so that order is maintained (i.e, 4 should come after 5 always)  
- Place 4 in `[5, 9, 8]` starting at index 1 (if we place at 0, order is disturbed)
- Place 4 in `[9, 5, 8]` starting at index 2
- Place 4 in `[9, 8, 5]` starting at index 3  

For bigger BSTs, tracking these indexes can be tricky. For this I'm wrapping starting index of next number with the list itself:  
`([5, 9, 8], 0)` ; With this we know that next number should be entered from index = 1  

Only thing that remains is adding the root element at index 0 in the merged list as root element HAS to come before any element.  
ex: if 7 was the root node, our result become:  
`[[7, 5, 9, 8], [7, 9, 5, 8], [7, 9, 8, 5]]`  

### Coming to the code  
- remove_indexes (list)  
This is a utility function which strips the indexes from the list of tuples so that we get the desired list of list.
- place_num_in_lst (num, list, start_idx)  
This function takes a number and places at all possible positions in list starting at index start_idx
- merge_list_with_lol (list, list_of_list)  
This function takes a list and merges with all the lists present in list_of_list
- merge (list_of_list, list_of_list, root)  
This function accepts left sequences and right sequences and merges them and appends the root before returning
- find_sequences(root_node)  
This is the driver function which recursively calls left and right subtree and merges them until we get the final output.
