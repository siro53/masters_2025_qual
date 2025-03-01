#!/bin/sh

SCRIPT_DIR=$(pwd)
SOURCE_FILE=$SCRIPT_DIR/$1
INPUT_FILE=$SCRIPT_DIR/tools/$2
OUTPUT_FILE=$SCRIPT_DIR/output.txt
EXEC_FILE=$SCRIPT_DIR/a.out

g++ -std=c++20 -O2 -DDEBUG -Wall -Wextra $SOURCE_FILE
cd $SCRIPT_DIR/tools
cargo run -r --bin tester $EXEC_FILE < $INPUT_FILE > $OUTPUT_FILE