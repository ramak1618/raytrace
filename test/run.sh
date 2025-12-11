# move to the directory of script file
pushd $(dirname $0) > /dev/null

# run test.java
java --class-path "../bin/" "test.java"

# move to the initial directory 
popd > /dev/null
