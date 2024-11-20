FROM debian:bullseye

# update and upgrade package manager
RUN apt-get update -y && apt-get upgrade -y && \

# download packages required by wp
RUN apt-get install -y php7.3 \
	php-fpm \
	php-mysql \
	mariadb-client

# download wp
RUN apt-get install -y wget && \
	wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www

# unzip wp files
RUN cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_FR.tar.gz

# upgrade perms on wp dir
RUN chown -R root:root /var/www/wordpress

# download wp command interpreter
# move it to /bin
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp

# open port req by subj
EXPOSE 8010

# copy setup script to /bin
COPY ./wp_init.sh /usr/local/bin/wp_init.sh
RUN chmod +x /usr/local/bin/wp_init.sh

# launch setup script at startup
ENTRYPOINT ["/usr/local/bin/wp_init.sh"]
