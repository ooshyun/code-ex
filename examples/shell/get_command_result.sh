#!bin/bash

# ipaddr=host.iptime.org
# port=12345
# ping -q -c 1 -w 15 $ipaddr >/dev/null 2>/dev/null
# pingres=$?

# echo $pingres
# if [ $pingres -eq 0 ]; then
#     echo "ping success"
# else
#     echo "ping fail"
# fi

# nmap_cmd="nmap -p $port $ipaddr | awk"
# echo $nmap_cmd
# nmapres=$($nmap_cmd)
# echo $nmapres



# version=$(python3.7 --version)

# echo $version

# if [ "$version" != "" ]; then
#     echo "python 3.6 version is installed."
# else
#     echo "python is not installed."
# fi


# python_version="3.7"
# version=$(python$python_version --version)
# echo $version

process_name="ssh"
test_cmd=$(ps -a | grep $process_name | grep -v grep)

echo $test_cmd

if [ -n "$test_cmd" ]; then
    echo "found."
else
    echo "not found."
fi


result=$(ssh docker.cochl.iptime.org "echo $(pwd)")
echo $result

pkg_name="python3.7"
host="docker.cochl.iptime.org"
search_package(){
    searchResult=$(ssh $host"
    apt search $pkg_name 2>/dev/null | grep \"^$pkg_name/\"
    ")

    echo $searchResult

    if [[ -n $searchResult ]]; then
        echo "Success to install $pkg_name"
        echo 1
    else 
        echo "Fail to install $pkg_name"
        echo 0
    fi
}

result_search_pkg= search_package
echo $result_search_pkg