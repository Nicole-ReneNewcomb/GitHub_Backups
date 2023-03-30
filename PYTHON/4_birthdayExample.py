# CIS024C Python Programming: Lupita's Lookup App by Nicole-Rene Newcomb
# Original sample files graciously provided by Gabriel Solomon (Thank you!)  

import os.path
import json

# Using os.path library function to determine current directory
# Useful for when program may run on different machines or OS
filePath = os.path.join(os.path.dirname(__file__), "4_birthday.json")


# Try to open a file and throw a error if it is not found
try:
    jsonFile = open(filePath, 'r')
except OSError:
    print("ERROR: Unable to open the file %s" % filePath)
    exit(-1)


# Read the whole json file into a variable (List type)
birthdayList = json.load(jsonFile)

# Create an empty dictionary
birthdayDictionary = {}

# Loop json list of data and put each name and birthday into a dictionary
for elem in birthdayList:

    # Fetch name and birthday
    name = elem["name"]
    birthday = elem["birthday"]

    # Add each name: birthday to dictionary as key-value pairs
    birthdayDictionary[name] = birthday


# Get user input for name to lookup
name = input("Enter a name: ")

# Create Lookup dictionary
lookupDictionary = {}

# Lookup matching names from dictionary
for key in birthdayDictionary:
    if name in key:
        print(key + "'s birthday is: " + birthdayDictionary[key])
    else:
        print("No match found.")

# To print a value in the dictionary by giving it a string with the name as the key
print("'s birthday is: " + birthdayDictionary["Jocelyn Jones"])