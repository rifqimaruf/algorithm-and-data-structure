# Duplicate Emails

## Approach
The function starts by creating a list called lst which contains all the values from the "email" column of the person DataFrame. This is done using the tolist() method of the DataFrame, which converts the column values into a Python list.

Next, an empty dictionary called res is created to store the email addresses as keys and their respective counts as values. The function then iterates over each email address in the lst list. If the email address is already present in the res dictionary, its count is incremented by 1. Otherwise, a new key-value pair is added to the dictionary with the email address as the key and an initial count of 1.

Finally, the function returns a new DataFrame that contains only the email addresses that have a count greater than 1. This is achieved by using a dictionary comprehension to filter out the email addresses.

