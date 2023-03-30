# CIS024C Python Programming: Lupita's Lookup App by Nicole-Rene Newcomb
# Original sample files graciously provided by Gabriel Solomon (Thank you!)  

import os.path
import json

# Using os.path library function to determine current directory
filePath = os.path.join(os.path.dirname(__file__), "4_birthday.json")


# Try to open a file and throw a error if it is not found
try:
    jsonFile = open(filePath, 'r')
except OSError:
    print("ERROR: Unable to open the file %s" % pathToFile)
    exit(-1)


# read the whole json file into a variable
birthdayList = json.load(jsonFile)

# create an empty dictionary
birthdayDictionary = {}

# loop json list of data and put each name and birthday into a dictionary
for elem in birthdayList:

    # fetch name and birthday
    name = elem["name"]
    birthday = elem["birthday"]

    print("name = " + name)
    print("birthday = " + birthday)

    birthdayDictionary[name] = birthday


# to print a value in the dictionary by giving it a string with the name as the key
print("Jocelyn Jones's birthday is: " + birthdayDictionary["Jocelyn Jones"])

# to get user input
name = input("Enter a name:")
print("name = " + name)
