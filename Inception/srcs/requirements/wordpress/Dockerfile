FROM debian:bullseye

# update and upgrade package manager
RUN apt-get update -y && apt-get upgrade -y

# download packages required by wp
RUN apt-get install -y \
    php \
    php-fpm \
    php-mysql \    
    curl

# download wp command interpreter
# move it to /bin
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
chmod +x wp-cli.phar && \
mv wp-cli.phar /usr/local/bin/wp

# copy wp conf file
COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/

RUN mkdir -p /run/php
WORKDIR	/var/www/wordpress/

# copy setup script to /bin
COPY ./wp_init.sh /usr/local/bin/wp_init.sh
RUN chmod +x /usr/local/bin/wp_init.sh

# open port req by subj
EXPOSE 9000


# launch setup script at startup
ENTRYPOINT ["/usr/local/bin/wp_init.sh"]