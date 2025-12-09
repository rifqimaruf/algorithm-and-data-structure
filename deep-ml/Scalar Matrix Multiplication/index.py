def scalar_multiply(matrix: list[list[int|float]], scalar: int|float) -> list[list[int|float]]:
  result = []
  for row in matrix:
    new_row = []
    for element in row:
      new_row.append(element * scalar)
    result.append(new_row)
  return result

matrix = [[1, 2], [3, 4]]
scalar = 2
output = scalar_multiply(matrix, scalar)
print(output)