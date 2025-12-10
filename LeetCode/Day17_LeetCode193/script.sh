#!/bin/bash
echo "Searching for phone numbers..."
grep -P '^(\d{3}-\d{3}-\d{4}|\(\d{3}\) \d{3}-\d{4})$' phoneNumber.txt