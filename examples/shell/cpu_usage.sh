#!/bin/bash
n_cpu_usage=0
total_cpu_usage=0.0
program_name="sense-stream"
n_core=$(nproc)
pid=$(pgrep -o $program_name)
sample_count=5
temp=$(pidstat -p $pid 1 $sample_count | sed -n '$p')
cpu_usage_irix=$(echo "$temp" | awk '{print $8}')

cpu_usage_nobc=$(echo "scale=2; $cpu_usage_irix / $n_core")  # solaris mode
total_cpu_usage_nobc=$(echo "$total_cpu_usage + $cpu_usage_nobc")

cpu_usage=$(echo "scale=2; $cpu_usage_irix / $n_core" | bc)  # solaris mode
total_cpu_usage=$(echo "$total_cpu_usage + $cpu_usage" | bc -l)

echo "program_name: $program_name"
echo "n_core: $n_core"
echo "pid: $pid"
echo "sample_count: $sample_count"
echo "temp: $temp"
echo "cpu_usage_irix: $cpu_usage_irix"

echo "cpu_usage: $cpu_usage"
echo "total_cpu_usage: $total_cpu_usage"

echo " no bc"
echo "cpu_usage: $cpu_usage_nobc"
echo "total_cpu_usage: $total_cpu_usage_nobc"


test_bc=$(echo "scale=2; 1.0 / 3.0" | bc -l)
echo "test_bc: $test_bc"
test_bc=$(echo "scale=2; 1.0 / 3.0" | bc)
echo "test_bc: $test_bc"
