def quick_sort(s: list) -> list:
    """
        Perform 'Quick' sort.
    """
    if len(s) == 0:
        return []

    pivot_elem_ix = len(s) // 2
    pivot_elem = s[pivot_elem_ix]

    left_ptr = 0
    right_ptr = len(s) - 1

    # Divide source list to 2 parts
    while (left_ptr <= right_ptr):
        while left_ptr < len(s) and s[left_ptr] < pivot_elem:
            left_ptr += 1

        while right_ptr >= 0 and s[right_ptr] > pivot_elem:
            right_ptr -= 1

        if left_ptr <= right_ptr:
            # Swap found elements
            s[left_ptr], s[right_ptr] = s[right_ptr], s[left_ptr]
            left_ptr += 1
            right_ptr -= 1

    # Perform same routines for each part
    if right_ptr + 1 == left_ptr:
        return quick_sort(s[:right_ptr + 1]) + quick_sort(s[left_ptr:])
    else:
        return quick_sort(s[:right_ptr + 1]) + [s[right_ptr + 1]] + quick_sort(s[left_ptr:])

a = [19, 4, 5, 17, 1]
b = [16, 19, 2, 12, 20, 15, 20, 15]
print(quick_sort(a))
