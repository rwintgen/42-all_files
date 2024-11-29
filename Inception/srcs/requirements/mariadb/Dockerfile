FROM debian:bullseye

# update and upgrade package manager
# install mariadb
RUN apt-get update -y && apt-get upgrade -y && apt-get install -y \
	mariadb-server

# copy mariadb conf file
COPY conf/mariadb.conf /etc/mysql/mariadb.conf.d/50-server.cnf

# copy the script
COPY mdb_init.sh /usr/local/bin/mdb_init.sh
RUN chmod 755 /usr/local/bin/mdb_init.sh

# open port req by subj
EXPOSE 3306

# launch && setup mariadb
CMD ["/usr/local/bin/mdb_init.sh"]