
FROM ubuntu:latest

RUN apt-get update

RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends tzdata

RUN apt-get install -y build-essential wget git

WORKDIR /usr/src

RUN wget https://github.com/Kitware/CMake/releases/download/v3.21.4/cmake-3.21.4-linux-x86_64.tar.gz

RUN tar -xf cmake-3.21.4-linux-x86_64.tar.gz

COPY . /usr/src/calculator

WORKDIR /usr/src/calculator

RUN chmod +x dockerCMake.sh

RUN /usr/src/calculator/dockerCMake.sh

CMD [ "/usr/src/calculator/bin/Calculator_exe" ]