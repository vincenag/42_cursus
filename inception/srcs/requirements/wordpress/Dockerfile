FROM debian:bullseye

RUN mkdir -p /var/www/html \
    && apt-get update \
    && apt-get install -y php php-fpm php-mysql \
    && apt-get install -y wget tar

COPY ./config/wp-config.php /var/www/html/wordpress/wp-config.php
COPY ./tools/script.sh .

EXPOSE 9000

RUN chmod +x script.sh
CMD ["bash", "script.sh"]