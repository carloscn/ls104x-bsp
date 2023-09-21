# /bin/bash

cd ramdisk
sudo find . | sudo cpio -H newc -o | gzip -9 > new_initramfs.cpio.gz

rm -rf ../new_initramfs.cpio.gz
mv new_initramfs.cpio.gz ../