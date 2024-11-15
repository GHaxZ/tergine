#!/bin/sh

# Settings
BINARY="tergine"
OUT_PATH="./out/$BINARY"
SRC_PATH="./src/"
LIBRARIES=("ncursesw" "m")

# Create output directory if it doesn't exist
mkdir -p "$(dirname "$OUT_PATH")"

# Find all .c files in the source path
FILES=$(find "$SRC_PATH" -name "*.c" | paste -sd " ")

# Prepare library arguments
LIBRARIES_ARGS=""
for LIB in "${LIBRARIES[@]}"; do
    LIBRARIES_ARGS="$LIBRARIES_ARGS -l$LIB"
done

# Compile
gcc $FILES $LIBRARIES_ARGS -o "$OUT_PATH" || exit 1

# Run the program
$OUT_PATH
