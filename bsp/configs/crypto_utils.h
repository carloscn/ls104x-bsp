/* Copyright (c) 2015 Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Freescale Semiconductor nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _CRYPTO_UTILS_H
#define _CRYPTO_UTILS_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

#include <global.h>

// ${WORK_PATH}/flexbuild_lsdk2108/components/apps/security/cst/common/include/crypto_utils.h

#define CRYPTO_HASH_CTX_SIZE	0x400

int crypto_extract_pub_key(char *fname_pub, uint32_t *len, uint8_t *key_ptr);
void crypto_hash_init(void *ctx);
void crypto_hash_update(void *ctx, void *data, uint32_t len);
void crypto_hash_final(void *hash, void *ctx);
int crypto_hash_update_file(void *ctx, char *fname);
int crypto_rsa_sign(void *img_hash, uint32_t len,
		void *rsa_sign, uint32_t *rsa_len, char *key_name);
void crypto_print_attribution(void);
uint32_t crypto_calculate_crc(void *data, uint32_t length);
uint32_t crypto_calculate_checksum(void *data, uint32_t num);
int autox_crypto_rsa_verify(void *img_hash, uint32_t len, void *rsa_sign,
			uint32_t rsa_len, char *key_name);
int autox_crypto_rsa_sign(void *img_hash, uint32_t len, void *rsa_sign,
						uint32_t *rsa_len, char *key_name);
int crypto_rsa_verify(void *img_hash, uint32_t len, void *rsa_sign,
			uint32_t rsa_len, char *key_name);
#endif
