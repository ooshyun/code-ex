#!/bin/bash
rm -rf tmp_config
rm -rf output.txt
touch tmp_config

function echo_to_file() {
    echo $1 $2 $3 $4

    arg1=$1
    arg2=$2
    arg3=$3
    arg4=$4

#     local config="# ${arg1} account\
# \nHost ${arg1}.host.iptime.org\
# \n\tHostName ${arg2}\
# \n\tUser ${arg3}\ 
# \n\tPort ${arg4}\
# \n\tAddKeysToAgent yes\
# \n\tIdentityFile ~/.ssh/id_rsa\n\n"
#     echo -e ${config} >> tmp_config
    
#     echo -e "# ${arg1} account\
# \nHost ${arg1}.host.iptime.org\
# \n\tHostName ${arg2}\
# \n\tUser ${arg3}\ 
# \n\tPort ${arg4}\
# \n\tAddKeysToAgent yes\
# \n\tIdentityFile ~/.ssh/id_rsa\n\n" >> tmp_config

    echo -e "# ${arg1} account\
             \nHost ${arg1}.host.iptime.org\
             \n\tHostName ${arg2}\
             \n\tUser ${arg3}\ 
             \n\tPort ${arg4}\
             \n\tAddKeysToAgent yes\
             \n\tIdentityFile ~/.ssh/id_rsa\n\n" >> tmp_config
}

USER_NAME="hello-world"
IP_ADDR="127.0.0.1"
PORT="8989"
PASSWORD="1234"
echo_to_file $USER_NAME $IP_ADDR $PORT $PASSWORD

USER_NAME="hello-world-2"
IP_ADDR="127.0.0.2"
PORT="1212"
PASSWORD="1234"
echo_to_file $USER_NAME $IP_ADDR $PORT $PASSWORD

cat tmp_config

multiline_string="Line 1
Line 2
Line 3
Line 4"

# Output the multiline string to a text file
echo "$multiline_string" > output.txt

