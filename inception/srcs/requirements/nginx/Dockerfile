FROM debian:bullseye

# Install nginx
RUN apt-get update && apt-get install -y nginx && apt-get -y install openssl

# Copy the configuration file
COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./tools/script.sh .

EXPOSE 443

RUN chmod +x /script.sh

CMD ["bash", "script.sh"]
