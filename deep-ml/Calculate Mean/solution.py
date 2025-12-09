def calculate_matrix_mean(matrix: list[list[float]], mode: str) -> list[float]:
  if not matrix:
    return []

  if mode == 'row':
    means = [sum(row) / len(row) for row in matrix]
  elif mode == 'column':
    num_cols = len(matrix[0])
    means = [sum(row[i] for row in matrix) / len(matrix) for i in range(num_cols)]
  else:
    # Mengembalikan daftar kosong jika mode tidak valid
    means = []
    
  return means