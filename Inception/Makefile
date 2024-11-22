all:
	@sudo hostsed add 127.0.0.1 rwintgen.42.fr && echo "successfully added rwintgen.42.fr to /etc/hosts"
	sudo docker compose -f ./srcs/docker-compose.yml up -d

clean:
	sudo docker compose -f ./srcs/docker-compose.yml down --rmi all -v
#	uncomment the following line to remove the images too
#	sudo docker system prune -a

fclean: clean
	@sudo hostsed rm 127.0.0.1 rwintgen.42.fr && echo "successfully removed rwintgen.42.fr to /etc/hosts"
	@if [ -d "/home/rwintgen/data/wordpress" ]; then \
	sudo rm -rf /home/rwintgen/data/wordpress/* && \
	echo "successfully removed all contents from /home/rwintgen/data/wordpress/"; \
	fi;

	@if [ -d "/home/rwintgen/data/mariadb" ]; then \
	sudo rm -rf /home/rwintgen/data/mariadb/* && \
	echo "successfully removed all contents from /home/rwintgen/data/mariadb/"; \
	fi;

re: fclean all

ls:
	sudo docker image ls
	sudo docker ps

.PHONY: all, clean, fclean, re, ls