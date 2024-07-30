FROM debian:buster

# Install Mariadb
RUN apt-get update -y && apt-get install -y mariadb-server

# Copy the configuration file
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d
# Copy the script
COPY ./tools/maria.sh /

# Change the permissions
RUN chmod +x /maria.sh

# Expose the port
EXPOSE 3306

CMD ["/maria.sh"]

