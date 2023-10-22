#!bin/bash

uninstall_venv_python() {
    deactivate
    rm -rf ./venv    
}

python3.8 -m venv ./venv

source ./venv/bin/activate
python --version

uninstall_venv_python