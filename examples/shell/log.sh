#!/bin/bash

function log() {
    for arg in "$@"; do
        if [ "${debug}" = true ]; then
            echo "[$(date +'%F %T')] ${arg}" >> ${workspaceFolder}/build.log
        else
            echo "[$(date +'%F %T')] ${arg}" 
        fi
    done
    # if [ "${debug}" = true ]; then
    #     echo "[$(date +'%F %T')] $@" >> ${workspaceFolder}/build.log
    # else
    #     echo "[$(date +'%F %T')] $@" 
    # fi
}


log "This is a log message."

# TODO: Add a command result (e.g. tree) to the log message.
x=$(tree .)

log  "This is another log message." \
     "This message is too long to fit in one line." \
     "So, I split it into multiple lines." \ 
     "$x" \
     "This is the end of the log message." 