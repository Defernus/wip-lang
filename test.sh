#!/bin/bash

set -e

recurse() {
	for i in "$1"/*.c;do
		if [ -f "$i" ] && [[ ! $i =~ "main.c" ]]; then
			printf "${i} $files"
		fi
	done
	for i in "$1"/*;do
		if [ -d "$i" ];then
			recurse "$i"
		fi
	done
}

SRC="./tests/main.c $(recurse ./src)"
OUT_FOLDER=./build
OUT=$OUT_FOLDER/test

mkdir -p $OUT_FOLDER

cc $SRC -I ./src -o $OUT
$OUT