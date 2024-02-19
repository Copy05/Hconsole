#!/bin/bash/

if [ "dpkg -s gcc" ]
then
    echo "Building..."
else
    echo "gcc has not been installed"
    exit
fi

gcc -Iinclude ./src/*.c ./src/*.h -o hc.out

echo "Succsessfully built!"
echo "NOTE: Hconsole has been discontinued on Jun 6, 2023. Please stop using this Tool"