FROM debian:bullseye

# update and upgrade package manager
# install nginx && openssl
RUN apt-get update -y && apt-get upgrade -y && \
	apt install -y nginx openssl

RUN mkdir -p /run/nginx
# create dir to store nginx certificate
RUN mkdir -p /etc/nginx/ssl

COPY ./conf/nginx.conf /etc/nginx/conf.d
RUN chmod -R 755 /etc/nginx /var/www/html
# create a self-signed cert
# do not set a passphrase
# storage location of cert && key
# auto-fill prompt for cert info
RUN openssl req -x509 \
	-nodes \
	-out /etc/nginx/ssl/inception.crt \
	-keyout /etc/nginx/ssl/inception.key \
	-subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=rwintgen.42.fr/UID=rwintgen"

EXPOSE 442
# copy nginx conf file
# COPY conf/nginx.conf /etc/nginx/nginx.conf

# upgrade perms on dirs needed by conf file
RUN chmod 755 /var/www/html && \
	chown -R www-data:www-data /var/www/html

# start nginx
CMD [ "nginx", "-g", "daemon off;" ]