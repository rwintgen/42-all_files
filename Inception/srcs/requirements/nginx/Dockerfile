FROM debian:bullseye

# update and upgrade package manager
# install nginx && openssl
RUN apt-get update -y && apt-get upgrade -y && \
	apt install -y nginx OpenSSL

# create dir to store nginx files
RUN mkdir -p /var/run/nginx

# create a self-signed cert
# do not set a passphrase
# storage location of cert && key
# auto-fill prompt for cert info
RUN openssl req -x509 \
	-nodes \
	-out /etc/nginx/ssl/inception.crt \
	-keyout /etc/nginx/ssl/inception.key \
	-subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=login.42.fr/UID=login"

# copy nginx conf file
COPY conf/nginx.conf /etc/nginx/nginx.conf

# upgrade perms on dirs needed by conf file
RUN chmod 755 /var/www/html && \
	chown -R www-data:www-data /var/www/html

# start nginx
CMD [ "nginx", "-g", "daemon off;" ]