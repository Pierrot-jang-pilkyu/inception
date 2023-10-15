FROM debian:buster

EXPOSE 3306

RUN apt-get -y update &&\
    apt-get -y upgrade &&\
    apt-get -y install mariadb-server\
    vim\
    procps

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./tools/setup.sh setup.sh

ENTRYPOINT [ "bash", "setup.sh" ]

CMD [ "mysqld_safe" ]
