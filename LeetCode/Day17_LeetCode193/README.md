# **Day 17: Solving LeetCode Problem 193 - Valid Phone Numbers**

## **Problem Statement**
Write a bash script that reads a file containing a list of phone numbers (`phoneNumber.txt`) and outputs all valid phone numbers. A valid phone number must:
- Be in one of the following formats:
  - `XXX-XXX-XXXX`
  - `(XXX) XXX-XXXX`
  - `XXX XXX XXXX`
- Ensure consistency with line endings and formatting for accurate matching.

The input file `phoneNumber.txt` may have different line endings or hidden characters that need to be accounted for.

## **Steps to Solve**

### **1. Analyze Input File**
The input file (`phoneNumber.txt`) contains phone numbers in multiple formats. However, when the script was initially executed, it produced no output. This was due to the presence of `^M` characters, indicating Windows-style line endings (`\r\n`).

Used the following command to inspect the file:
```bash
cat -A phoneNumber.txt
```

### **2. Convert Line Endings**
To ensure the file could be correctly processed, the line endings were converted from Windows-style to Unix-style using `dos2unix`:
```bash
dos2unix phoneNumber.txt
```

### **3. Write the Script**
The script uses `grep` with Perl-compatible regular expressions (`-P`) to match valid phone number formats:
```bash
#!/bin/bash
echo "Searching for valid phone numbers..."
grep -P '^(\d{3}-\d{3}-\d{4}|\(\d{3}\) \d{3}-\d{4})$' phoneNumber.txt
```

### **4. Test the Script**
- After converting the file's line endings, executed the script:
  ```bash
  bash script.sh
  ```
- Verified that the output matched all valid phone numbers in the file.

---

## **Solution Script**

```bash
#!/bin/bash
# LeetCode Problem 193: Valid Phone Numbers
echo "Searching for valid phone numbers..."
grep -P '^(\d{3}-\d{3}-\d{4}|\(\d{3}\) \d{3}-\d{4})$' phoneNumber.txt
```

---

## **Example Input and Output**

### Input (`phoneNumber.txt`):
```
987-123-4567
123 456 7890
(123) 456-7890
{123} 123-4567
```

### Output:
```
987-123-4567
123 456 7890
(123) 456-7890
```

### Exlanation
- `^`: Matches the beginning of a line.
- `(\d{3}-\d{3}-\d{4})`: Matches the format `xxx-xxx-xxxx`.
- `|\(\d{3}\) \d{3}-\d{4}`: Matches the format `(xxx) xxx-xxxx`.
- `$`: Matches the end of a line.


Note: `{123} 123-4567` is not valid according to the problem's constraints and is excluded from the output.

---

## **Lessons Learned**
1. **File Line Endings:**
   - Always check and standardize line endings when working with files from different systems.
   - Use tools like `dos2unix` or `sed` to handle line ending conversions.

2. **Regular Expressions:**
   - Understanding regex is crucial for solving pattern-matching problems effectively.
   - `grep -P` is powerful for tasks requiring Perl-compatible regex.

3. **Debugging Techniques:**
   - Use `cat -A` to inspect hidden characters in input files.
   - Break down and test regex patterns incrementally to isolate issues.

---

