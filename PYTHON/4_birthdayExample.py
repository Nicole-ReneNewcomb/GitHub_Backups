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

# Create boolean to indicate if user input is valid
nameValid = False

# Get user input for name to lookup & validate input
while nameValid == False:
    name = input("\nEnter a name: ").lower()
    if name.isalpha():
        nameValid = True
    else:
        print("\nPlease enter letters only.")

# Create boolean to indicate if name found in dictionary
nameFound = False

# Lookup matching names from dictionary keys
for key in birthdayDictionary:
    if name in key.lower():
        print("Here are the names and birthdays of matching friends: ")
        print("======================================================")
        print("Name                          Birthday")
        print("======================================================")
        print(key + "'s birthday is: " + birthdayDictionary[key])
        nameFound = True

# If name not found within dictionary keys
if nameFound == False:
    print("No match found.")