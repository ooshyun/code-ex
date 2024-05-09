#!/bin/bash

git_url="git@github.com:SeunghyunOh-Cochl/Git-release-test.git"

release="v0.0.1"
# release="v0.0.2"

# Check if the folder contains any files
result=$(gh release --repo ${git_url} view ${release} --json assets --jq '.assets[].name')
result=$(gh release --repo ${git_url} view ${release} --json assets | jq '.assets[0].id')
echo $result
if [ "$result" ]; then
    echo "Files exist in the folder."
else
    echo "No files in the folder."
fi