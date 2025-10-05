import numpy as np

def matrix_dot_vector(a: list[list[int|float]], b: list[int|float]) -> list[int|float] | int:
    matrix = np.array(a)
    vector = np.array(b)

    if matrix.ndim != 2:
        return -1
    if matrix.shape[1] != vector.shape[0]:
        return -1
    
    result = matrix @ vector
    return result.tolist()

a1 = [[1, 2], [2, 4]]
b1 = [1, 2]
print(f"Test 1 Output: {matrix_dot_vector(a1, b1)}")