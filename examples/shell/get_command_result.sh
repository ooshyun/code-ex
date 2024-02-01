#!bin/bash

ipaddr=host.iptime.org
port=12345
ping -q -c 1 -w 15 $ipaddr >/dev/null 2>/dev/null
pingres=$?

echo $pingres
if [ $pingres -eq 0 ]; then
    echo "ping success"
else
    echo "ping fail"
fi

nmap_cmd="nmap -p $port $ipaddr | awk"
echo $nmap_cmd
nmapres=$($nmap_cmd)
echo $nmapres



version=$(python3.7 --version)

echo $version

if [ "$version" != "" ]; then
    echo "python 3.6 version is installed."
else
    echo "python is not installed."
fi