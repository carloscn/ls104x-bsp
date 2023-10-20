include ./build.cfg
export $(shell sed 's/=.*//' ./build.cfg)

.PHONY: clean distclean libp11

SHELL:=/bin/bash

openssl:
	@echo "[INFO] Building ${LIBSSL} ..."
	@wget --no-check-certificate https://www.openssl.org/source/old/1.1.1/openssl-1.1.1s.tar.gz
	@rm -rf $(LIBSSL)
	@tar -xvf $(LIBSSL).tar.gz
	@cd $(LIBSSL) && CC=gcc ./config --prefix=$(OPENSSL_OUT) no-asm
	@cd $(LIBSSL) && sed -i 's/-m64/ /' Makefile
	@make -C $(LIBSSL) -j16
	@make -C $(LIBSSL) install -j16
	@echo "[INFO] Build openssl done..."
	@rm -rf $(LIBSSL).tar.gz
	@rm -rf $(PWD)/out/man
	@rm -rf $(PWD)/out/share/doc
	@rm -rf $(PWD)/out/share/man
	@rm -rf $(LIBSSL).tar.gz
	@rm -rf $(LIBSSL)

curl:
	@echo "[INFO] Building ${LIBCURL}..."
	@wget --no-check-certificate ${LIBCURL_ADDR}
	@tar -xvf ${LIBCURL}.tar.gz
	@cd ${LIBCURL} && ./configure --host=aarch64-none-linux-gnu --prefix=${LIBCURL_OUT} CFLAGS="-I${LIBSSL_OUT}/include" LDFLAGS="-L${LIBSSL_OUT}/lib"
	@make -C ${LIBCURL} -j16
	@make -C ${LIBCURL} install
	@echo "[INFO] ${LIBCURL} build done!"
	@rm -rf ${LIBCURL}*

libxml2:
	@echo "[INFO] Building ${LIBXML2}..."
	@wget --no-check-certificate ${LIBXML2_ADDR}
	@tar -xvf ${LIBXML2}.tar.gz
	@cd ${LIBXML2} && ./configure --host=aarch64-none-linux-gnu --prefix=${LIBXML2_OUT}"
	@make -C ${LIBXML2} -j16
	@make -C ${LIBXML2} install
	@echo "[INFO] ${LIBXML2} build done!"
	@rm -rf ${LIBXML2}*

archive: libxml2
	@echo "[INFO] Building ${LIBARCHIVE}..."
	@wget --no-check-certificate ${LIBARCHIVE_ADDR}
	@tar -xvf ${LIBARCHIVE}.tar.gz
	@cd ${LIBARCHIVE} && ./configure --host=aarch64-none-linux-gnu --prefix=${LIBARCHIVE_OUT}"
	@make -C ${LIBARCHIVE} -j16
	@make -C ${LIBARCHIVE} install
	@echo "[INFO] ${LIBARCHIVE} build done!"
	@rm -rf ${LIBARCHIVE}*

clean:
	@rm -rf *.tar.gz
	@rm -rf $(LIBSSL)
	@rm -rf libp11
	@rm -rf builds
	@rm -rf build
	@rm -rf hse/libhse/obj
	@rm -rf hse/libpkcs/obj
	@rm -rf hse/tests/obj
	@rm -rf ${LIBCURL}*