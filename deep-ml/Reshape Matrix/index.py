import numpy as np

def reshape_matrix(a: list[list[int|float]], new_shape: tuple[int, int]) -> list[list[int|float]]:
	try:
		numpy_array = np.array(a)
		reshaped_array = numpy_array.reshape(new_shape)
		reshaped_matrix = reshaped_array.tolist()
		return reshaped_matrix
	except ValueError:
		return []
	
a = [[1,2,3,4],[5,6,7,8]]
new_shape = (4, 2)
output = reshape_matrix(a, new_shape)
print(output)
