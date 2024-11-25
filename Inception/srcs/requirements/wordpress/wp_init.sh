#!/bin/bash

# let mdb_init.sh finish
sleep 10

# autofill wp startup fields
wp config create	--allow-root \
					--dbname=$SQL_DATABASE \
					--dbuser=$SQL_USER \
					--dbpass=$SQL_PASSWORD \
					--dbhost=mariadb:3306 --path='/var/www/wordpress'

#launch php-fpm
/usr/sbin/php-fpm7.4 -F
