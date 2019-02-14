#!/bin/bash

# Check command param
if [[ $# -ne 2 && $# -ne 3 ]]; then
	echo "$0 [command] [index] <target>"
	exit
fi

COMMAND=$1
INDEX=$2
TARGET=$3
BINARY="test"

create_source(){
	TEXT=$(<"$1")
	TEMPLATE=$(<main.cpp.tpl)
	echo "${TEMPLATE//class-solution-impl/$TEXT}" > "$2"
}

if [[ "$COMMAND" = "init" ]]; then
	if [[ ! -d "$INDEX" ]]; then
		mkdir -p "$INDEX"
		touch "$INDEX/$TARGET.cpp"
	else
		echo "dir is exist"
	fi
elif [[ "$COMMAND" = "build" ]]; then
	SRC_PATH=$(find $INDEX -name "*.cpp")
	create_source $SRC_PATH "main.cpp"
	g++ --std=c++11 "main.cpp" -o $BINARY
    echo "*****************RUN*****************"
    ./test
fi

