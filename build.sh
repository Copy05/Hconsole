#!/bin/bash/

if [ "dpkg -s g++" ]
then
    echo "Building..."
else
    echo "g++ has not been installed"
    exit
fi

g++ -o hc.out ./src/*.c ./src/*.h

echo "Succsessfully built!"
echo "Use Hconsole with caution and responsible!"