def digital_root(n):
    while n>=10:
        n = sum(int(digit) for digit in str(n))

    return n

def main():
    # User input numbers
    n = int (input("Enter a number: "))

    print(f"The digital root of {n} is: {digital_root(n)}")

if __name__ == "__main__":
    main()