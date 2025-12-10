import re


# playground 1
# pattern = "[a-zA-Z0-9]+@[a-zA-Z]+\.(com|edu|net)"
# user_input = input()

# if(re.search(pattern, user_input)):
#     print("valid email")
# else:
#     print("invalid email")


# # playground 2
# pattern = r"^[a-zA-Z0-9.*-+]+@[a-zA-Z]+\.(com|edu|net)$"
# user_input = input("Enter your email address: ")

# if(re.search(pattern, user_input)):
#     print("valid email")
# else:
#     print("invalid email")

# material 1
# there is frase called metacharacter in regex, metacharacter means, those character doesnt represent their literal values, instead they have a special purpose which to control how regex engine intepretate
# there is many kind of metacharacter in regex, for example "^", "$", ".", "[]", and more 
# ^ defined match the beginning of the string
# $ defined as match the end of the string
# * defined as match the preceding zero or more times, its "greedy" quantifier
# and more

# playground 3
# log parser
pattern = r"^\[(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2},\d{3})\]\s+(\w+):\s+(.*)$"

user_input = input("Enter your log: ")

match = re.search(pattern, user_input)

if match:
    timestamp = match.group(1)
    level = match.group(2)
    message = match.group(3)

    print("Timestamp:", timestamp)
    print("Level:", level)
    print("Message:", message)
else:
    print("No match found.")



