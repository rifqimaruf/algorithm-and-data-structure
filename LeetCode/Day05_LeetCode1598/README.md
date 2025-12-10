# Log Folder

## Problem Description
We are given a list of logs representing directory navigation operations. Each log entry can be one of the following:
- `"../"` : Move up to the parent directory.
- `"./"` : Stay in the current directory (no change).
- A direcotry name (`"d1/"`): Move to the specific directory

## Approach
First we using the stack concept. By initialize it with library vector. Iterate through each log entry:
- if the log is `"../"`: Pop the top direcotry from the stack. means go back to the parent diretory
- if the log is `"./"`: Ignore it, stay at the same directory
- Otherwise, directory name : Push the diretory onto the stack

