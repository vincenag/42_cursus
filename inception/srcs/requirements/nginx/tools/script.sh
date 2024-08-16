#!/bin/bash

mkdir -p /etc/nginx/ssl

sed -i "s#__MY_DOMAIN__#$DOMAIN_NAME#g" /etc/nginx/nginx.conf
sed -i "s#__CERTIFICATE_KEY__#$CERTIFICATE_KEY#g" /etc/nginx/nginx.conf
sed -i "s#__CERTIFICATE__#$CERTIFICATE_#g" /etc/nginx/nginx.conf

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -out $CERTIFICATE_ -keyout $CERTIFICATE_KEY -subj "/C=SP/ST=Andalucia/L=Malaga/O=42/OU=42/CN=$DOMAIN_NAME/UID=$LOGIN_"


nginx -g 'daemon off;'