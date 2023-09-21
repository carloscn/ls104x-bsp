# ls104x-bsp


booti 0x80000000 - 0x90000000


setenv bootargs 'console=ttyS0,115200 root=/dev/sda3 rw rootwait earlycon=uart8250,mmio,0x21c0500; '
setenv bootcmd 'usb start; fatload usb 0:2 0x80000000 Image; fatload usb 0:2 0x90000000 fsl-ok1046a-1133-5a59-c2.dtb; booti 0x80000000 - 0x90000000'



setenv bootdelay 3
setenv bootcmd 'run distro_bootcmd; run qspi_bootcmd; env exists secureboot && esbc_halt;'
setenv bootargs 'console=ttyS0,115200 root=/dev/mmcblk0p1 rw rootwait earlycon=uart8250,mmio,0x21c0500'



fatload mmc 0:2 0x80000000 Image; fatload mmc 0:2 0x90000000 fsl-ok1043a-1455-c3.dtb; booti 0x80000000 - 0x90000000;


fatload mmc 0:2 0x80000000 Image; fatload mmc 0:2 0x90000000 fsl-ok1043a-1455-c3.dtb; booti 0x80000000 - 0x90000000;

setenv bootargs console=ttyS0,115200 root=PARTUUID=dc408262-03 rw rootwait earlycon=uart8250,mmio,0x21c0500

setenv bootargs 'console=ttyS0,115200 root=root=/dev/ram0 rw ip=dhcp rootwait earlycon=uart8250,mmio,0x21c0500; '
setenv bootargs 'console=ttyS0,115200 root=/dev/mmcblk0p3 rw rootwait earlycon=uart8250,mmio,0x21c0500; '
setenv bootcmd 'usb start; fatload usb 0:2 0xb0000000 image.ub; bootm 0xb0000000'

setenv bootcmd 'mmc dev 0; fatload mmc 0:2 0xb0000000 image.ub; bootm 0xb0000000'

setenv bootcmd 'mmc dev 0; fatload mmc 0:2 0x80000000 Image; fatload mmc 0:2 0x90000000 fsl-ok1046a-1133-5a59-c2.dtb; booti 0x80000000 - 0x90000000;'
