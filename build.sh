#!/bin/bash

set -e 

if [ ! -d "build" ]; then
	mkdir build
fi
cd build

cmake ..
make

echo "alyssa osipova tcp-task done!"

if [ -f "client" ] && [ -f "server" ]; then
	echo "client and server exist"
else 
	echo "failed to create files"
fi
