#!/bin/sh

docker container rm -f $(docker container ls -aq)
docker image rm -f $(docker image ls -q)
docker network rm srcs-inception
docker volume rm srcs_mariadb_data srcs_wordpress_data
sudo rm -rf /home/$USER/data
