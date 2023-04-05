#!/usr/bin/env python3.11

# File named contains.py : script takes word and searches/returns all matching values
# Searches for matching values in separate dictionary text file

import argparse 
parser = argparse.ArgumentParser(description='Search for words including partial word') 
parser.add_argument('snippet', help='partial (or complete) string to search for in words')
args = parser.parse_args() 
snippet = args.snippet.lower() 
#with open('/usr/share/dict/words') as f:  
    #words = f.readlines() 
#matches = [] 
#for word in words:   
    #if snippet in word.lower():       
        #matches.append(word)

#Alternative way to find matches and output results
words = open('/usr/share/dict/words').readlines()
matches = [word.strip() for word in words if snippet in word.lower()] 
print(matches)
#Alternative if not needing to store list in matches; just prints instead of assigning to matches
#print([word.strip() for word in words if snippet in word.lower()])
