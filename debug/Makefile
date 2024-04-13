DOCKER_IMAGE_NAME = gdb_docker

all: build run

build:
	docker build -t $(DOCKER_IMAGE_NAME) .

run:
	docker run -v /usr/share/zoneinfo/Europe/Madrid:/etc/localtime:ro -it --rm $(DOCKER_IMAGE_NAME) 

clean:
	docker system prune -af
