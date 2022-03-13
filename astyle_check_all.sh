#!/bin/bash
# Check http://astyle.sourceforge.net/astyle.html


WS_DIR=$(dirname $(readlink -f $0))
ASTYLE_SCRIPT_PATH=$WS_DIR/astyle_check_single_file.sh
cd $WS_DIR


# for filename in Src/*; do
#    $ASTYLE_SCRIPT_PATH $filename
# done
$ASTYLE_SCRIPT_PATH example.cpp



# Delelte temp file and Cause an error if code style is not ok 
if [ -s "temp_astyle_output.txt" ]
then
   echo "Your code does not correspond to the code style."
   rm temp_astyle_output.txt
   exit 1
fi
rm temp_astyle_output.txt