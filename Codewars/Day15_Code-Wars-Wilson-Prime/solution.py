import math

def am_i_wilson(P):
    if P <= 1:
        return False
    if not is_prime(P):
        return False
    if not is_prime(P):
        return False
    factorial_part = math.factorial(P - 1) + 1
    result = factorial_part % (P * P)
    return result == 0

def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    
    return True
def main():
    test_numbers = [5, 13, 563, 7, 10]
    for number in test_numbers:
        if am_i_wilson(number):
            print(f"{number} is a Wilson prime.")
        else:
            print(f"{number} is not a Wilson prime.")

if __name__ == "__main__":
    main()

