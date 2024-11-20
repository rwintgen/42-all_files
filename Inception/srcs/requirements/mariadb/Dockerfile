FROM debian:bullseye

# update and upgrade package manager
# install mariadb
RUN RUN apt-get update -y && apt-get upgrade -y && \
	apt-get install -y mariadb-server

# copy mariadb conf file
COPY conf/mariadb.conf /etc/mysql/mariadb.conf.d/50-server.cnf

# open port req by subj
EXPOSE 3306

# launch && setup mariadb
CMD ["./mdb_init.sh"]