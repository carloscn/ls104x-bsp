# !/bin/bash
set -uex

RAMDISK_PATH=/home/haochenwei/work/ls104x-bsp/initramfs/ramdisk_ostree
CROSS_COMPILE=/home/haochenwei/opt/cross-compile/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin

${CROSS_COMPILE}/aarch64-none-linux-gnu-gcc ostree-prepare-root-static.c -I ./ -o ostree-prepare-root && \
cp -rfv ostree-prepare-root ${RAMDISK_PATH}/usr/bin/ostree-prepare-root

${CROSS_COMPILE}/aarch64-none-linux-gnu-gcc ostree-remount.c -I ./ -o ostree-remount && \
cp -rfv ostree-prepare-root ${RAMDISK_PATH}/usr/bin/ostree-remount