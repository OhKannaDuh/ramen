#!/bin/bash

SCRIPT_DIRECTORY=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
BASE_DIRECTORY="$SCRIPT_DIRECTORY/.."
BUILD_DIRECTORY="$BASE_DIRECTORY/build"

mkdir -p $BUILD_DIRECTORY
cmake -B $BUILD_DIRECTORY -S $BASE_DIRECTORY
cmake --build $BUILD_DIRECTORY
