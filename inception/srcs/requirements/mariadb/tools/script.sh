#!/bin/bash

mkdir -p /run/mysqld

cat << EOF > config.sql

CREATE DATABASE IF NOT EXISTS ${MARIADB_DATABASE};
CREATE USER IF NOT EXISTS '${MARIADB_USER}'@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PASSWORD}';
GRANT ALL PRIVILEGES ON *.* TO '${MARIADB_USER}'@'%';
FLUSH PRIVILEGES;

EOF

chmod 777 config.sql
chown -R mysql:root /run/mysqld
chown -R mysql:mysql /var/lib/mysql
mv config.sql /var/lib/mysql/config.sql
mariadbd --init-file /var/lib/mysql/config.sql

