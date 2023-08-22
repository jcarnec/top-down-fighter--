#!/bin/bash

# Get the list of .h files in the directory
header_files=$(ls *.h)

# Loop through each header file
echo "These are the header files of my project so far" > temp.txt
for file in $header_files; do
    # Print the filename at the top and then cat the contents
    echo "/* Filename: $file */" > temp.txt
    cat "$file" >> temp.txt
    echo "" >> temp.txt
done

# Combine all contents into a single file
cat temp.txt | xclip -selection clipboard

# Clean up temporary file
rm temp.txt

echo "Header files concatenated and copied to clipboard."

