#!/bin/bash

echo "Testing single commands: "

.././rshell < single_test
if[$? -eq 0]
then
	echo "Passed"
else
	echo "Failed"
fi	