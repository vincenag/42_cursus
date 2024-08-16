#!/bin/sh

wget -O /tmp/wordpress.tar.gz https://wordpress.org/latest.tar.gz
tar -xzf /tmp/wordpress.tar.gz -C /var/www/html

mkdir -p /run/php

chown -R www-data:www-data /var/www/html/wordpress
chmod -R 755 /var/www/html/wordpress


sed -i "s/__MARIADB_DATABASE__/$MARIADB_DATABASE/" /var/www/html/wordpress/wp-config.php
sed -i "s/__MARIADB_USER__/$MARIADB_USER/" /var/www/html/wordpress/wp-config.php
sed -i "s/__MARIADB_PASSWORD__/$MARIADB_PASSWORD/" /var/www/html/wordpress/wp-config.php


wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

wp core install --allow-root \
  --url=$DOMAIN_NAME \
  --title=Inception \
  --admin_user=$WP_ADMIN \
  --admin_password=$WP_ADMIN_PASSWORD \
  --admin_email=$WP_ADMIN_EMAIL \
  --skip-email --path=/var/www/html/wordpress

wp user create --allow-root $WP_USER $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD \
  --path=/var/www/html/wordpress --url=$DOMAIN_NAME

sed -i 's#listen = /run/php/php7.4-fpm.sock#listen = 9000#g' /etc/php/7.4/fpm/pool.d/www.conf

/usr/sbin/php-fpm7.4 -F