FROM debian:bullseye

RUN mkdir -p /var/www/html
VOLUME [ "/var/www/html" ]

# nginx에 필요한 패키지 설치
RUN apt-get update -y && apt-get upgrade -y && \
    apt-get -y install nginx openssl vim

# ssl 인증서 생성
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \ 
     -keyout /etc/ssl/private/server_pkey.pem -out /etc/ssl/certs/server.crt \
     -subj "/C=KR/ST=Seoul/L=Gang-nam/O=42seoul/OU=inception/CN=pjang.42.fr"

# default 설정
COPY ./conf/default /etc/nginx/sites-available/default

# nginx 서비스 시작
ENTRYPOINT [ "nginx", "-g", "daemon off;" ]