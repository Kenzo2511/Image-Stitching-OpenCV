FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y build-essential && apt-get install -y cmake && apt install -y libopencv-dev
COPY ../ /home/project
RUN rm -rf /home/project/build && mkdir -p /home/project/build
WORKDIR /home/project/build
RUN cmake .. && make -j10