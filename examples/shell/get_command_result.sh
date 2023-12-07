#!bin/bash

ipaddr=cochl.iptime.org
port=5353
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
