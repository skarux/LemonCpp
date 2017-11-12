#!/bin/bash

LEMON_CPP_EXE="./LemonCpp"
SKELETHON_PATH="../skelethon/"
SKELETHON_FILE="lempar.cpp"
EXAMPLES_PATH="../examples/"
EXAMPLES_NUMBER=2

FILE_NAME_PARSER="ParserExample"
FILE_NAME_MAIN="Example"

############################################################################################################

for i in {1..2}
do
  # generate parser source code
  $LEMON_CPP_EXE -t$SKELETHON_PATH -T$SKELETHON_PATH$SKELETHON_FILE $EXAMPLES_PATH$FILE_NAME_PARSER$i.y
  
  if [ $? -eq 0 ]; then
    g++ -o $FILE_NAME_MAIN$i $EXAMPLES_PATH$FILE_NAME_MAIN$i.cpp $EXAMPLES_PATH$FILE_NAME_PARSER$i.cpp
  fi
done



