import numpy as np
def linear_regression_normal_equation(X: list[list[float]], y: list[float]) -> list[float]:
	X_matrix = np.array(X)
	y_vector = np.array(y)
	try:
		# Calculate the transpose of X
		X_transpose = X_matrix.T
		# Calculate the inverse of (X^T * X)
		X_transpose_X_inv = np.linalg.inv(X_transpose.dot(X_matrix))
		# Calculate the final coefficients
		theta = X_transpose_X_inv.dot(X_transpose).dot(y_vector)
	except np.linalg.LinAlgError:
		raise ValueError("The matrix X^T*X is singular and cannot be inverted.")

	return np.round(theta, 4).tolist()