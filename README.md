# sudoko_solver

Takes a 9×9 2D array grid[9][9], and assigns digits (from 1 to
9) to the empty cells so that every row, column, and subgrid
of size 3×3 contains exactly one instance of the digits from 1
to 9. 

Using Backtracking, and Bitmask.

#Complexity Analysis:  

1)Time complexity: O(9^(n*n)). For every unassigned index, there are 9 possible options so the time complexity is O(9^(n*n)). The time complexity remains the same but checking if a number is safe to use is much faster, O(1).
2)Space Complexity: O(n*n). To store the output array a matrix is needed, and 3 extra arrays of size n are needed for the bitmasks.
