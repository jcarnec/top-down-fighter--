#!/bin/bash

# Function to concatenate files
concatenate_files() {
  for file in "$1"/*.h; do
    filename=$(basename "$file")
    echo "/* === $filename === */"
    cat "$file"
    echo -e "\n/* === End of $filename === */\n"
  done
}

# Main script
main() {
  if [ $# -ne 1 ]; then
    echo "Usage: $0 <directory>"
    exit 1
  fi

  directory="$1"

  if [ ! -d "$directory" ]; then
    echo "Error: Directory '$directory' does not exist."
    exit 1
  fi

  concatenated_content=$(concatenate_files "$directory")

  # Check if xclip is installed
  if command -v xclip >/dev/null 2>&1; then
    echo -n "$concatenated_content" | xclip -selection clipboard
    echo "Concatenated content copied to clipboard."
  else
    echo "Error: 'xclip' is not installed. You can install it using your package manager."
    exit 1
  fi
}

# Run the script
main "$@"
