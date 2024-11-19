FROM debian:buster

RUN apt update \
	apt install nginx -y OpenSSL -y

RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=login.42.fr/UID=login"

COPY conf/nginx.conf /etc/nginx/nginx.conf

RUN chmod 755 /var/www/html && \
	chown -R www-data:www-data /var/www/html

CMD [ "nginx", "-g", "daemon off;" ]