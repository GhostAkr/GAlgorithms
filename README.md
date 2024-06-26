# GAlgorithms

## Brief repo description
Here are some useful algorithms and tools implemented in different programming languages. These 
algorithms are implemented for fun and are not pretended to be 100% effcient and correct.

## Repo contents

### Algorithms
- ``[C++] bst_successor_search`` — algorithm searching for an inorder successor of given node. 
  Inorder successor of the given node is the node with the smallest key greater then the
  key of the input node.
- ``[PY] file_max_word`` — algorithm searching for the longest word in a text file (implemented 
  in Python);
- ``[JL] inverse_matr`` — set of algorihtms calculating inverse matrices:
  - ``ExplicitInverse3x3.jl`` — calculation of inverse 3x3 matrix via hardcoded formulas;
- ``[C++] sudoku_validator`` — Sudoku field validator. Validates given Sudoku field according to
  known Sudoku rules. Note: to enter empty cell in a field use '0'.  
- ``[PY] merge_sort`` — "Merge" sort implemented in Python;
- ``[PY] quick_sort`` — "Quick" sort implemented in Python;
- ``[C++] copy_and_swap`` – implementation of copy-and-swap idiom in C++.
- ``[C++] split_str_view`` – splitting string to words in C++ via ``std::string_view``.

### Patterns
- ``[C++] decorator`` – implementation of decorator pattern in C++.
- ``[C++] singleton`` – implementation of singleton pattern in C++.
- ``[C++] factory`` – implementation of factory pattern in C++.

### Tools
- ``[C++] NonCopyable`` – implementation of non-copyable idiom in C++.
- ``[C++] vector_remove`` – implementation of erase-remove idiom in C++ applied to
  ``std::vector``.
- ``[C++] CowPtr`` – implementation of copy-on-write (copy-on-non-const to be more presice) 
  idiom in C++.
