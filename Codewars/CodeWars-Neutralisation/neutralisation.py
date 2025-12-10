def interact_strings(str1, str2):
    if len(str1) != len(str2):
        raise ValueError("Both strings must be of the same length.")
    
    result = []
    
    for char1, char2 in zip(str1, str2):
        if char1 == '+' and char2 == '+':
            result.append('+')
        elif char1 == '-' and char2 == '-':
            result.append('-')
        elif (char1 == '+' and char2 == '-') or (char1 == '-' and char2 == '+'):
            result.append('0')
        else:
            raise ValueError("Strings must only contain '+' and '-'.")
    
    return ''.join(result)

def main():
    str1 = input("Enter the first string: ")
    str2 = input("Enter the second string: ")
    
    result = interact_strings(str1, str2)
    print("The result of interaction is:", result)

if __name__ == "__main__":
    main()