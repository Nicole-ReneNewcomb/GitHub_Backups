#!/usr/bin/env python3.11

import argparse
import sys            # Used to allow for changing of code (0: success to 1-2: error) when exception thrown

parser = argparse.ArgumentParser(description='Read a file in reverse')  # Creates object from class

# Assign help description; accessed by entering: reverse-file -h
parser.add_argument('filename', help='the file to read')         # Adds object argument “filename” (required/positional)

# Create optional arguments (options) with primary name (--) and alias (-)
# Pass in optional argument to script example: reverse-file --limit 5 testing.txt
parser.add_argument('--limit', '-l', type=int, help='the number of lines to read') 

# Create optional argument that uses built-in action from library package
# reverse-file --version : outputs reverse-file 1.0 and doesn’t finish rest of script (exits)
parser.add_argument('--version', '-v', action='version', version='%(prog)s 1.0') 
args = parser.parse_args()                          # Default uses sys.argv arguments

# Use try/except/else/finally statement to prevent standard error when running file w/o filename argument
try:
    f = open(args.filename)
    limit = args.limit
except FileNotFoundError as err:
     print(f"Error: {err}")
     sys.exit(2)                     # Modifies closing program code to be 2 instead of 0 to indicate exception error
else:
    with f:
        lines = f.readlines()
        lines.reverse()
        if limit:
            lines = lines[:limit]
        for line in lines:
            print(line.strip()[::-1])

# Previous code before try/except/else block added
#with open(args.filename) as f:    
    #lines = f.readlines()                           # Returns individual lines within list data structure
    #lines.reverse()                                 # Reverses the order of lines within list
    #if args.limit:                                  # If limit value for number of lines passed to script
        #lines = lines[:args.limit]                  # Reassign to list only lines within included limit (slice)
    #for line in lines:                                  
        #print(line.strip()[::-1])                   # strip() removes \n and spaces; -1 step value reverses
