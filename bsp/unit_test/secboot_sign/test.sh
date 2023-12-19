# !/bin/bash

# verify signed_data.bin = dec_sign_stripped.bin
echo "################################################################################ test verify"
openssl rsautl -raw -verify -in signed_data.bin -inkey autox_pub_key_pkcs8.pem -pubin > dec_sign.bin
./strip_rsa_dec dec_sign.bin dec_sign_stripped.bin

hd dec_sign_stripped.bin
hd to_sign_data.bin

echo "################################################################################ test sign"
# sign dec_sign.bin = signed_data.bin
openssl rsautl -raw -sign -inkey autox_pri_key.pem -in dec_sign.bin > enc_sign.bin

hd enc_sign.bin
hd signed_data.bin