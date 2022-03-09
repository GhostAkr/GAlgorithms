def merge_two_list(a: list, b:list) -> list:
    """
        Merges to sorted list into one sorted list.
    """
    res_lst = []

    # Check special cases
    if len(a) == 0:
        if len(b) == 0:
            return res_lst
        return b
    if len(b) == 0:
        return a

    a_pos = 0
    b_pos = 0
    while (a_pos < len(a) or b_pos < len(b)):
        if a_pos >= len(a):
            res_lst.append(b[b_pos])
            b_pos += 1
            continue
        if b_pos >= len(b):
            res_lst.append(a[a_pos])
            a_pos += 1
            continue
            
        a_val = a[a_pos]
        b_val = b[b_pos]
        if a_val <= b_val:
            res_lst.append(a_val)
            a_pos += 1
        else:
            res_lst.append(b_val)
            b_pos += 1
    
    return res_lst

def merge_sort(s: list) -> list:
    """
        Perform merge sort
    """
    if len(s) == 1:
        return s
    
    center_elem_ix = len(s) // 2

    return merge_two_list(merge_sort(s[:center_elem_ix]), merge_sort(s[center_elem_ix:]))
