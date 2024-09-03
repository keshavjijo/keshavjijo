#!/bin/bash


# Check whether enough parameters are given,

if [ $# -lt 2 ] ; then
   echo "usage: $0 rwxrwxrwx file/directory name"
   echo "Example: $0 rwxrw-r-- myfile"
   exit 99
fi

# Check whether the destination file/directory exists.

if [ ! -f $2 ] && [ ! -d $2 ]; then
   echo "File/Directory not found!"
   exit 99
   else
   if [ -f $2 ]; then
      fileordirectory="file"
   else
      fileordirectory="directory"
   fi
   echo "$2 is a $fileordirectory"
fi

# Check whether a correct permission parameter is given.

if [ $(echo "${#1}") != 9 ]; then
   echo "Permission code should be 9 characters long."
   exit 99
fi

nerror=0
if [ $(echo ${1:0:1}) != "r" ] && [ $(echo ${1:0:1}) != "-" ]; then
   echo "The 1st character of the permission should be either r or -"
   nerror=$(($nerror+1))
fi
if [ $(echo ${1:1:1}) != "w" ] && [ $(echo ${1:1:1}) != "-" ]; then
   echo "The 2nd character of the permission should be either w or -"
   nerror=$(($nerror+1))
fi
if [ $(echo ${1:2:1}) != "x" ] && [ $(echo ${1:2:1}) != "-" ]; then
   echo "The 3rd character of the permission should be either x or -"
   nerror=$(($nerror+1))
fi
if [ $(echo ${1:2:1}) = "-" ] && [ $fileordirectory="directory" ]; then
   echo "The 3rd character of the permission for a directory should be x"
   nerror=$(($nerror+1))
fi
if [ $(echo ${1:3:1}) != "r" ] && [ $(echo ${1:3:1}) != "-" ]; then
   echo "The 4th character of the permission should be either r or -"
   nerror=$(($nerror+1))
fi
if [ $(echo ${1:4:1}) != "w" ] && [ $(echo ${1:4:1}) != "-" ]; then
   echo "The 5th character of the permission should be either w or -"
   nerror=$(($nerror+1))
fi
if [ $(echo ${1:5:1}) != "x" ] && [ $(echo ${1:5:1}) != "-" ]; then
   echo "The 6th character of the permission should be either x or -"
   nerror=$(($nerror+1))
fi
if [ $(echo ${1:6:1}) != "r" ] && [ $(echo ${1:6:1}) != "-" ]; then
   echo "The 7th character of the permission should be either r or -"
   nerror=$(($nerror+1))
fi
if [ $(echo ${1:7:1}) != "w" ] && [ $(echo ${1:7:1}) != "-" ]; then
   echo "The 8th character of the permission should be either w or -"
   nerror=$(($nerror+1))
fi
if [ $(echo ${1:8:1}) != "x" ] && [ $(echo ${1:8:1}) != "-" ]; then
   echo "The 9th character of the permission should be either x or -"
   nerror=$(($nerror+1))
fi

if [ $nerror -gt 0 ]; then
   exit 99
fi

# Translate the permission code to the equivalent integer code

ur=0
uw=0
ux=0
gr=0
gw=0
gx=0
or=0
ow=0
ox=0

if [ $(echo ${1:0:1}) = "r" ]; then
   ur=400
fi
if [ $(echo ${1:1:1}) = "w" ]; then
   uw=200
fi
if [ $(echo ${1:2:1}) = "x" ]; then
   ux=100
fi
if [ $(echo ${1:3:1}) = "r" ]; then
   gr=40
fi
if [ $(echo ${1:4:1}) = "w" ]; then
   gw=20
fi
if [ $(echo ${1:5:1}) = "x" ]; then
   gx=10
fi
if [ $(echo ${1:6:1}) = "r" ]; then
   or=4
fi
if [ $(echo ${1:7:1}) = "w" ]; then
   ow=2
fi
if [ $(echo ${1:8:1}) = "x" ]; then
   ox=1
fi

ichmod=$(($ur+$uw+$ux+$gr+$gw+$gx+$or+$ow+$ox))

# Apply the permission code to the file/directory.

chmod $ichmod $2

# Goodbye message

echo "Permission was changed!"
if [ $fileordirectory = "file" ]; then
   echo $(ls -l $2)
