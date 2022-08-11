from ubuntu:latest
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y gcc net-tools socat musl-dev gdb python3
WORKDIR /pwn

RUN useradd hacker
USER hacker
COPY ./buffer.c /pwn/buffer.c
COPY ./flag.txt /pwn/flag.txt

USER root
RUN gcc -fno-stack-protector -mpreferred-stack-boundary=4 -z execstack -o /pwn/buffer /pwn/buffer.c
RUN rm /pwn/buffer.c
RUN chmod 001 /pwn/buffer
RUN chmod 004 /pwn/flag.txt

RUN chmod go-rx /usr/bin/passwd

USER hacker

ENTRYPOINT ["socat"]
CMD ["-d", "-d", "TCP4-LISTEN:31338,fork,reuseaddr", "EXEC:'/pwn/buffer',pty,echo=0,raw,iexten=0"]
EXPOSE 31338
