FROM ubuntu:latest

RUN apt update && apt install -y \
	nasm \
	binutils \
	gdb

WORKDIR /app

COPY debug_file.s /app/debug_file.s
COPY gdb_commands.txt /app/gdb_commands.txt

RUN nasm -f elf64 -gdwarf -o debug_file.o debug_file.s
RUN ld -o debug debug_file.o

CMD ["bash"]
#CMD ["gdb", "-x", "gdb_commands.txt"]
