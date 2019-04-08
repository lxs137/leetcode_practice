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
	SOURCE_FILE=$1
	HEADER_FILE="${SOURCE_FILE//.cpp/.h}"
	if [[ -e "$HEADER_FILE" ]]; then
		TEXT=$(<"$HEADER_FILE")$'\n'$(<"$SOURCE_FILE")
	else
		TEXT=$(<"$SOURCE_FILE")
	fi
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
    # cpplint --linelength=120 --filter=-legal/copyright main.cpp
    if g++ --std=c++11 "main.cpp" -o $BINARY; then
        echo "*****************RUN*****************"
        ./test
    fi
fi

