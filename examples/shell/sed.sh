#!bin/bash
# prev_key="pattern1"
# key="pattern2"

prev_key="pattern2"
key="pattern1"

echo "prev_key: ${prev_key}"
echo "will change key to ${key}"
sed -i '' "s|${prev_key}|${key}|g" ./test/test.cc  # mac
# sed -i "s|${prev_key}|${key}|g" ./test/test.cc
