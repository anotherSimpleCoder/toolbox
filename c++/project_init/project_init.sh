#!/bin/sh
CMAKE_VERSION=3.30

echo Enter your project name
read project_name

mkdir $project_name
cp CMakeLists.txt $project_name
(
cd $project_name
sed \
        -e "s/#min_version#/$CMAKE_VERSION/g" \
        -e "s/#proj_name#/$project_name/g" \
        CMakeLists.txt > CMakeLists.txt
echo "Generated CMakeLists.txt"
touch main.cc
)
