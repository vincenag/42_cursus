FROM debian:bullseye

# Install Mariadb
RUN apt-get update -y && apt-get install -y mariadb-server

# Copy the configuration file
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d
# Copy the script
COPY ./tools/script.sh .

# Change the permissions
RUN chmod +x /script.sh

RUN chmod 644 /etc/mysql/mariadb.conf.d/50-server.cnf

# Expose the port
EXPOSE 3306

CMD ["bash", "script.sh"]

