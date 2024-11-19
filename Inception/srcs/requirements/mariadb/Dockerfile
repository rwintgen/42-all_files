FROM debian:buster

RUN RUN apt-get update -y && apt-get upgrade -y \
	apt install -y nginx
	
RUN apt-get install -y mariadb-server

COPY conf/mariadb.conf /etc/mysql/mariadb.conf.d/50-server.cnf