#!/bin/sh
# sleep 10

# sed -i 's/index index.html index.htm index.nginx-debian.html index.php;/index index.html index.htm index.php;/gi' /etc/nginx/sites-available/default

nginx -g daemon off;