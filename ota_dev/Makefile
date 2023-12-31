include ./build.cfg
export $(shell sed 's/=.*//' ./build.cfg)

.PHONY: clean distclean aktualizr

SHELL:=/bin/bash

prepare: boost openssl sqlite3 buildroot libs

buildroot:
	@echo "[INFO] Building ${BUILDROOT}..."
	@wget --no-check-certificate -nc ${BUILDROOT_ADDR}
	@tar -xvf ${BUILDROOT}.tar.gz
	@cp -rfv configs/autox_tcu_defconfig ${BUILDROOT}/configs/
	@cd ${BUILDROOT} && make autox_tcu_defconfig
	@cd ${BUILDROOT} && make
	@echo "[INFO] ${BUILDROOT} build done!"

buildroot_config:
	@echo "[INFO] Building ${BUILDROOT}..."
	@wget --no-check-certificate -nc ${BUILDROOT_ADDR}
	@tar -xvf ${BUILDROOT}.tar.gz
	@cp -rfv configs/autox_tcu_defconfig ${BUILDROOT}/configs/
	@cd ${BUILDROOT} && make autox_tcu_defconfig
	@cd ${BUILDROOT} && make meuconfig
	@echo "[INFO] ${BUILDROOT} build buildroot_config done!"

buildroot_use_config:
	@echo "[INFO] Building ${BUILDROOT}..."
	@cd ${BUILDROOT} && make
	@echo "[INFO] ${BUILDROOT} build done!"

libs:
	-@cd ${BUILDROOT_OUT}/libcurl-8.4.0 && make install DESTDIR=${BUILDROOT_OUT}/libcurl-8.4.0/out
	-@cd ${BUILDROOT_OUT}/libsodium-1.0.18 && make install DESTDIR=${BUILDROOT_OUT}/libsodium-1.0.18/out
	-@cd ${BUILDROOT_OUT}/libostree-2023.1 && make install DESTDIR=${BUILDROOT_OUT}/libostree-2023.1/out
	-@cd ${BUILDROOT_OUT}/libarchive-3.6.2 && make install DESTDIR=${BUILDROOT_OUT}/libarchive-3.6.2/out
	-@cd ${BUILDROOT_OUT}/libp11-0.4.12 && make install DESTDIR=${BUILDROOT_OUT}/libp11-0.4.12/out

openssl:
	@echo "[INFO] Building ${LIBSSL} ..."
	@wget --no-check-certificate -nc ${LIBSSL_ADDR}
	@rm -rf ${LIBSSL}
	@tar -xvf ${LIBSSL}.tar.gz
	@cd ${LIBSSL} && CC=gcc ./config --prefix=$(LIBSSL_OUT) no-asm
	@cd ${LIBSSL} && sed -i 's/-m64/ /' Makefile
	@make -C ${LIBSSL} -j16
	@make -C ${LIBSSL} install -j16
	@echo "[INFO] Build openssl done..."
	@rm -rf ${LIBSSL}.tar.gz
	@rm -rf $(PWD)/out/man
	@rm -rf $(PWD)/out/share/doc
	@rm -rf $(PWD)/out/share/man
	@rm -rf ${LIBSSL}.tar.gz
	@rm -rf ${LIBSSL}

curl:
	@echo "[INFO] Building ${LIBCURL}..."
	@wget --no-check-certificate -nc ${LIBCURL_ADDR}
	@tar -xvf ${LIBCURL}.tar.gz
	@cd ${LIBCURL} && ./configure --host=${HOST_FLAG} --prefix=${LIBCURL_OUT} CFLAGS="-I${LIBSSL_OUT}/include" LDFLAGS="-L${LIBSSL_OUT}/lib"
	@make -C ${LIBCURL} -j16
	@make -C ${LIBCURL} install
	@echo "[INFO] ${LIBCURL} build done!"
	@rm -rf ${LIBCURL}*

libxml2:
	@echo "[INFO] Building ${LIBXML2}..."
	@wget --no-check-certificate -nc ${LIBXML2_ADDR}
	@tar -xvf ${LIBXML2}.tar.gz
	@cd ${LIBXML2} && ./configure --host=${HOST_FLAG} --prefix=${LIBXML2_OUT}"
	@make -C ${LIBXML2} -j16
	@make -C ${LIBXML2} install
	@echo "[INFO] ${LIBXML2} build done!"
	@rm -rf ${LIBXML2}*

archive:
	@echo "[INFO] Building ${LIBARCHIVE}..."
	@wget --no-check-certificate -nc ${LIBARCHIVE_ADDR}
	@tar -xvf ${LIBARCHIVE}.tar.gz
	@cd ${LIBARCHIVE} && ./configure --host=${HOST_FLAG} --prefix=${LIBARCHIVE_OUT}"
	@make -C ${LIBARCHIVE} -j16
	@make -C ${LIBARCHIVE} install
	@echo "[INFO] ${LIBARCHIVE} build done!"
	@rm -rf ${LIBARCHIVE}*

jsoncpp:
	@echo "[INFO] Building ${JSONCPP}..."
	@rm -rf ${JSONCPP}.tar.gz ${JSONCPP}
	@wget --no-check-certificate -nc ${JSONCPP_ADDR} -O ${JSONCPP}.tar.gz
	@tar -xvf ${JSONCPP}.tar.gz
	@cd ${JSONCPP} && sed -i '95 a set(JSONCPP_WITH_TESTS OFF)' CMakeLists.txt
	@cd ${JSONCPP} && ln -s ../configs/cross-aarch64.cmake . && mkdir build
	@cd ${JSONCPP}/build && cmake -DCMAKE_TOOLCHAIN_FILE=../cross-aarch64.cmake -DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=${JSONCPP_OUT} ..
	@make -C ${JSONCPP}/build -j8
	@make -C ${JSONCPP}/build install
	@echo "[INFO] ${JSONCPP} build done!"

sqlite3:
	@echo "[INFO] Building ${SQLITE3}..."
	@wget --no-check-certificate -nc ${SQLITE3_ADDR} -O ${SQLITE3}.tar.gz
	@tar -xvf ${SQLITE3}.tar.gz
	@cd ${SQLITE3} && ./configure --host=${HOST_FLAG} --prefix=${SQLITE3_OUT}
	@make -C ${SQLITE3} -j16
	@make -C ${SQLITE3} install
	@echo "[INFO] ${SQLITE3} build done!"

boost:
	@echo "[INFO] Building ${BOOST}..."
	@wget --no-check-certificate -nc ${BOOST_ADDR}
	@tar -xvf ${BOOST}.tar.gz
	@cd ${BOOST} && echo "using gcc : arm : ${HOME}/opt/cross-compile/gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++ ;" > user_config.jam
	@echo "[INFO] the out put path is ${BOOST_OUT}"
	@cd ${BOOST} && ./bootstrap.sh --prefix=${BOOST_OUT}
	@cd ${BOOST} && ./b2 install toolset=gcc-arm cxxflags=-fPIC \
						 --with-system \
						 --with-filesystem \
						 --with-log \
						 --with-program_options \
						 -j32 --user-config=user_config.jam
	@cd ${BOOST} && ./b2 link=shared install toolset=gcc-arm cxxflags=-fPIC \
						 --with-system \
						 --with-filesystem \
						 --with-log \
						 --with-program_options \
						 -j32 --user-config=user_config.jam
	@echo "[INFO] ${BOOST} build done!"

aktualizr:
	@echo "[INFO] Building ${AKTUALIZR}..."
	-@git clone ${AKTUALIZR_ADDR}
	@source ${PWD}/build.cfg
	-@cd ${AKTUALIZR} && git submodule update --init --recursive
	@cd ${AKTUALIZR} && rm -rf build
	@cd ${AKTUALIZR} && mkdir -p build
	@cp -rfv ${PWD}/configs/CMakeLists.txt ${AKTUALIZR}/
	@cp -rfv ${PWD}/configs/cross-aarch64.cmake ${AKTUALIZR}/build/
	@cd ${AKTUALIZR}/build && cmake -DCMAKE_BUILD_TYPE=Debug -Fcross-aarch64.cmake ../
	@cd ${AKTUALIZR}/build && make aktualizr_lib
	@cd ${AKTUALIZR}/build && make aktualizr-c
	@cd ${AKTUALIZR}/build && mkdir -p out
	@cp -rfv ${AKTUALIZR}/build/src/libaktualizr-c/libaktualizr-c.so ${AKTUALIZR}/build/out
	@cp -rfv ${AKTUALIZR}/build/src/libaktualizr/libaktualizr.so ${AKTUALIZR}/build/out
	@ls -al ${AKTUALIZR}/build/out
	@echo "[INFO] ${AKTUALIZR} build done!"

clean:
	@rm -rf *.tar.gz