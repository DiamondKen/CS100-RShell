#!/bin/bash

echo "Testing multiple commands: "

cd ..  
cd ..
./rshell<<EOF>single_test
ls -a
EOF

if[$? -eq 0]
then
	echo "Passed"
else
	echo "Failed"
fi