# move to directory of the script file
pushd $(dirname $0) > /dev/null

# delete old compiled files
rm -r bin/* 2> /dev/null

# compile all files in src
javac $(find -regex "^\./src/.*\.java")  -d bin/

# move back to the initial directory
popd > /dev/null
