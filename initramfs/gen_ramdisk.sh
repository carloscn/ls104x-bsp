# /bin/bash
set -uxe

cd prepare_root
bash build.sh
cd -

cd ramdisk_ostree
sudo find . | sudo cpio -H newc -o | gzip -9 > new_initramfs.cpio.gz

rm -rf ../new_initramfs.cpio.gz
mv new_initramfs.cpio.gz ../
