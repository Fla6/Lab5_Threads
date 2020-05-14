FROM amazonlinux

COPY pingp.py /home/lab5/pingp.py

COPY multipingp.py /home/lab5/multipingp.py

COPY pingp.h /home/lab5/pingp.h

COPY ping.cpp /home/lab5/ping.cpp

COPY multiping.cpp /home/lab5/multiping.cpp

COPY input2.txt /home/lab5/input2.txt

RUN yum update -y

RUN yum install -y nano

RUN yum install -y gcc-c++

RUN yum install -y python3

RUN yum install -y nmap

ENTRYPOINT bin/bash