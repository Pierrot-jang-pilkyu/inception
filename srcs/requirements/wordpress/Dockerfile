FROM debian:buster
EXPOSE 9000

RUN mkdir -p /var/www/html
VOLUME [ "/var/www/html" ]

# wordpress에 필요한 패키지 설치
RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get -y install \
    php7.3 \
    php-fpm \
    php-cli \
    wget \
    curl \
    php-mysql \
    php-mbstring \
    php-xml \
    sendmail \
    vim

# www.conf 설정
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

# wp-cli 설치
RUN curl -O \
    https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin && \
    chmod +x /usr/local/bin/wp-cli.phar && \
    ln -sf /usr/local/bin/wp-cli.phar /usr/local/bin/wp

# wp-config 설정 및 php-fpm 서비스 시작
COPY ./tools/setup.sh setup.sh
ENTRYPOINT [ "bash", "setup.sh" ]
