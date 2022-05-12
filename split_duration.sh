#!/bin/bash

# https://stackoverflow.com/questions/5265839/split-delimited-file-into-smaller-files-by-column

cut -d'@' -f1 "$1" > "${1}.duration"
cut -d'@' -f2 "$1" > "${1}.returns"