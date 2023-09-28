#!/bin/bash
sleep 5

if ! wp core is-installed --allow-root --path=/var/www/html; then
    wp core download --path=/var/www/html --allow-root

    cp /var/www/html/wp-config-sample.php \
    /var/www/html/wp-config.php
    
    sed -i 's/database_name_here/'"$MYSQL_DATABASE"'/gi' /var/www/html/wp-config.php
    sed -i 's/username_here/'"$MYSQL_USER"'/gi' /var/www/html/wp-config.php
    sed -i 's/password_here/'"$MYSQL_PASSWORD"'/gi' /var/www/html/wp-config.php
    sed -i 's/localhost/mariadb:3306/gi' /var/www/html/wp-config.php

    cd /var/www/html
    wp config shuffle-salts --allow-root
    cd /

    wp core install --url=$WORDPRESS_URL \
                --title=inception \
                --admin_user=$WORDPRESS_ADMIN_USER \
                --admin_password=$WORDPRESS_ADMIN_PASSWORD \
                --admin_email=$WORDPRESS_ADMIN_EMAIL \
                --allow-root \
                --path=/var/www/html
    wp user create $WORDPRESS_USER_ID $WORDPRESS_USER_EMAIL \
                --user_pass=$WORDPRESS_USER_PASSWORD \
                --allow-root \
                --path=/var/www/html
fi

service php7.3-fpm start | php-fpm7.3 -F
