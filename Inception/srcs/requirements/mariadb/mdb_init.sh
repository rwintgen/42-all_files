#!/bin/bash

# start service
mysqld_safe &
sleep 5

# create and setup db
mysql -u root << eof
CREATE DATABASE IF NOT EXISTS \`$MYSQL_DATABASE\`;
CREATE USER IF NOT EXISTS \`$MYSQL_USER\`@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON \`$MYSQL_DATABASE\`.* TO \`$MYSQL_USER\`@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
FLUSH PRIVILEGES;
eof

# restart service
mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown
exec mysqld_safe
