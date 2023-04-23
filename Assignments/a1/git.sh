#1/bin/bash
  
GIT_LOG=$(git log)
GIT_LOG_ARR=($(echo "$GIT_LOG" | tr '\n' ' '))

for i in "${GIT_LOG_ARR[@]}"; do
  if [[ $i == Author* ]]; then
    author=$(echo $i | cut -d ' ' -f 2-)
  fi
  if [[ $i == Date* ]]; then
    date=$(echo $i | cut -d ' ' -f 5,6,7)
    echo "[$author]: $date"
  fi
done