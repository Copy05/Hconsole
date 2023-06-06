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
echo "Use Hconsole with caution and responsible!"