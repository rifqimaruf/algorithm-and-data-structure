# Longest Common Prefix - LeetCode Problem 14

## Problem Statement

Write a function to find the longest common prefix string among an array of strings.

If there is no common prefix, return an empty string `""`.

### Example 1:
**Input**: `strs = ["flower", "flow", "flight"]`  
**Output**: `"fl"`

### Example 2:
**Input**: `strs = ["dog", "racecar", "car"]`  
**Output**: `""`  
**Explanation**: There is no common prefix among the input strings.

### Constraints:
- `1 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`
- `strs[i] consists of only lowercase English letters`.

## Solution Approach

### Step-by-step Solution:

1. **Initial Assumption**:
   - Assume the first string in the list (`strs[0]`) is the longest common prefix (LCP).
   
2. **Iterate through the Strings**:
   - Start comparing the LCP with each subsequent string in the list.
   
3. **Compare Prefix**:
   - For each string, check how much of the current LCP matches the string.
   - Keep reducing the LCP by updating it to the matched portion.

4. **Early Exit**:
   - If at any point the LCP becomes an empty string, return `""` because no common prefix exists.

5. **Return Result**:
   - After comparing all strings, the remaining LCP is the longest common prefix.

### Example Walkthrough:

- **Input**: `["flower", "flow", "flight"]`
  - Start with the first string: `prefix = "flower"`
  - Compare with `"flow"`: Match up to `"fl"`, update prefix to `"fl"`.
  - Compare with `"flight"`: Match up to `"fl"`, keep prefix as `"fl"`.
  - **Result**: `"fl"`

- **Input**: `["dog", "racecar", "car"]`
  - Start with the first string: `prefix = "dog"`
  - Compare with `"racecar"`: No common prefix, so return `""`.
  - **Result**: `""`


## How to Run the Code

1. **Compile the Code**:
     ```bash
     g++ -Wall -o longest_common_prefix longest_common_prefix.cpp
     ```

2. **Run the Executable**:
     ```bash
     ./longest_common_prefix
     ```
