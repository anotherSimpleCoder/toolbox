FROM ubuntu:latest
USER root
RUN apt update && apt upgrade -y
RUN apt install -y clang build-essential git curl pkg-config software-properties-common lsb-release libtool autoconf unzip wget
RUN apt clean all

RUN git clone https://github.com/Kitware/CMake
WORKDIR ./CMake
RUN git checkout release
RUN ./bootstrap
RUN make -j$(nproc)
RUN make install
