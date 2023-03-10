#!/bin/bash/

if [ "dpkg -s g++" ]
then
    echo "Building..."
else
    echo "g++ has not been installed"
    exit
fi

g++ -o hc.out *.c *.h
echo "Use with caution and responsible!"