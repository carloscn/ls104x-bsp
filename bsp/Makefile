include build.cfg
export $(shell sed 's/=.*//' build.cfg)

SHELL := /bin/bash

.PHONY: clean tcu

tcu:
	#-git clone ${TCU_REPO} -b ${TCU_REPO_BRANCH} ${TCU_REPO_DIR}
	mkdir -p ${WORK_PATH}
	cp -rfv ${TCU_REPO_DIR}/bootloader/flexbuild_lsdk2108.tgz ${WORK_PATH}/
	cp -rfv ${TCU_REPO_DIR}/bootloader/ls1043_autox ${WORK_PATH}/
	cd ${WORK_PATH} && tar -xvf flexbuild_lsdk2108.tgz
	cp -rfv ${WORK_PATH}/ls1043_autox/* ${WORK_PATH}/flexbuild_lsdk2108/
	cp -rfv ${CONFIG_DIR}/sdk.yml ${WORK_PATH}/flexbuild_lsdk2108/configs/sdk.yml
	@echo "[INFO] prepare tcu workspace done!"

sync:
	cd ${WORK_PATH}/flexbuild_lsdk2108 && \
	source setup.env && \
	flex-builder -i repo-fetch && \
	flex-builder -i repo-update
	@echo "[INFO] sdk sync done!"

sdk:
	cd ${WORK_PATH}/flexbuild_lsdk2108 && \
	source setup.env && \
	flex-builder -c atf -m ls1043ardb -b sd && flex-builder -i mkfw -m ls1043ardb -b sd && \
	flex-builder -c atf -m ls1043ardb -b qspi && flex-builder -i mkfw -m ls1043ardb -b qspi
	ls -al ${WORK_PATH}/flexbuild_lsdk2108/build/images/*
	@echo "[INFO] sdk build done!"

boot:
	cd ${WORK_PATH}/flexbuild_lsdk2108 && \
	source setup.env && \
	flex-builder -c atf -m ls1043ardb -b sd && \
	flex-builder -c atf -m ls1043ardb -b qspi
	@echo "[INFO] uboot + tfa + rcw build done!"

linux:
	cd ${WORK_PATH}/flexbuild_lsdk2108 && \
	source setup.env && \
	flex-builder -c linux
	@echo "[INFO] linux kernel build done!"

optee:
	cd ${WORK_PATH}/flexbuild_lsdk2108 && \
	source setup.env && \
	flex-builder -c optee
	@echo "[INFO] optee build done!"

burn_boot:
	sudo dd if=${WORK_PATH}/flexbuild_lsdk2108/firmware_ls1043ardb_sdboot.img of=${UDISK}

clean:
	rm -rf ${WORK_PATH}
