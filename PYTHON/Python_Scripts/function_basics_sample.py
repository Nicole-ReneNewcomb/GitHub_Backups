#!/bin/env python3.11
def hello_world():                             # Called by entering: hello_world()
    print("Hello, World!")
def print_name(name):                          # Called by entering: print_name(“Larry”)
    print(f"Name is {name}")                   # Output: Name is Larry     
def add_two(num):                              # Called by entering: add_two(2)
    return num + 2                             # Returns: 4
result = add_two(2)                            # Result = 4
print(result)
hello_world()
print_name("Nicole-Rene")
