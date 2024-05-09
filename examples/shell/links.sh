cross_fix="aarch64-linux-gnu-"
root="/opt/opensdk/opensdk-5.00/linaro-aarch64-2020.09-gcc10.2-linux5.4/bin"
target="/opt/opensdk/opensdk-5.00/linaro-aarch64-2020.09-gcc10.2-linux5.4/aarch64-linux-gnu/bin"
tool=(ar as ld ld.bfd ld.gold nm objcopy objdump ranlib readelf strip)
for i in ${tool[@]}; do
    echo "$i is available"
    ln -s $root/$cross_fix$i $target/$i"
done