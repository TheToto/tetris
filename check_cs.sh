#!/bin/sh

grep --color=always "[^_]if(" src/* -r
grep --color=always "[^_]while(" src/* -r
grep --color=always "[^_]for(" src/* -r
grep --color=always "[^_]switch(" src/* -r
grep --color=always "( " src/* -r
grep --color=always " )" src/* -r
grep --color=always " $" src/* -r
grep --color=always "	" src/* -r
grep --color=always "[^/\* ]\* " src/* -r | grep -v "/\*"
grep --color=always "typedef" src/* -r
grep --color=always '.\{81\}' src/* -r
grep --color=always '[^ ] --' src/* -r
grep --color=always '[^ ] ++' src/* -r
