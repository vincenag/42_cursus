FROM debian:bullseye

RUN apt-get update && apt-get install -y nginx && apt-get -y install openssl

COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./tools/script.sh .

EXPOSE 443

RUN chmod +x /script.sh

CMD ["bash", "script.sh"]
