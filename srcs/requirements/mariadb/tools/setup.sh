#!/bin/sh

/etc/init.d/mariadb start

mysql -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;"
QUERY=$(echo $(mysql -e "select count(mysql.user.user) from mysql.user where mysql.user.user= 'pjang'"));

if [ "$QUERY" == "count(mysql.user.user) 0" ]
then
    mysql -e "CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
    mysql -e "GRANT ALL PRIVILEGES ON *.* TO '$MYSQL_USER'@'%';"
fi

mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '"$MYSQL_ROOT_PASSWORD"';"
mysql -uroot -p$MYSQL_ROOT_PASSWORD -e "FLUSH PRIVILEGES;"
mysqladmin -uroot -p$MYSQL_ROOT_PASSWORD shutdown
# mysqld --bind-address=0.0.0.0
mysqld_safe
