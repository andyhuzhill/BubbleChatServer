FROM ubuntu:latest

RUN sudo apt update && sudo apt upgrade -y

WORKDIR /var
COPY . /var

RUN cmake . && make -j4

EXPOSE 8080
