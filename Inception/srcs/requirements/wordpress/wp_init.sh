#!/bin/bash

# let mdb_init.sh finish
sleep 5

# autofill wp startup fields
wp core download --path="/var/www/html" --allow-root
wp config create --path="/var/www/html" --allow-root --dbname=$SQL_DATABASE --dbuser=$SQL_USER --dbpass=$SQL_PASSWORD --dbhost=$DB_HOST --skip-check
wp core install --path="/var/www/html" --allow-root --url=$WP_URL --title=$WP_TITLE --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PASS --admin_email=$WP_ADMIN_EMAIL --skip-email
wp user create --path="/var/www/html" --allow-root $WP_USER $WP_EMAIL --user_pass=$WP_PASS --role='contributor'

#launch php-fpm
exec /usr/sbin/php-fpm7.4 -F
