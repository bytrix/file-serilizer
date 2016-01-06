#!/usr/bin/python
import os
import sys
import re

cwd = os.getcwd()
files = os.listdir(cwd)
index = 0
ext = ''
if(len(sys.argv) > 1):
	ext = sys.argv[1]


for file in files:
	pattern = re.compile(r".*"+ext+"$")
	if(pattern.match(file)):
		index += 1
		print "mv "+"\""+file+"\"  >>>> "+str(index)+"."+ext

print '-'*50

print index, "file(s) in total"



def renameFiles():
	index = 0
	for file in files:
		pattern = re.compile(r".*"+ext+"$")
		if(pattern.match(file)):
			index += 1
			os.rename(file, str(index)+"."+ext)


check = raw_input("\nSure to apply these changed? (Y/n)")

if(check == 'Y' or check == 'y'):
	renameFiles()
	print "Ok!"
elif(check == 'n' or check == 'N'):
	print 'Goodbye!'

