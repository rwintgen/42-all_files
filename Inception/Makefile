all:
	@mkdir -p ~/data/wordpress
	@mkdir -p ~/data/mariadb
	@mkdir -p ~/data/website
	@docker compose -f ./srcs/docker-compose.yml up -d --build

down:
	@docker compose -f ./srcs/docker-compose.yml down

re:
	@docker compose -f srcs/docker-compose.yml up -d --build

clean:
	@docker compose -f ./srcs/docker-compose.yml down -v
	@docker compose -f ./srcs/docker-compose.yml stop
	@docker volume rm -f `docker volume ls`
	@sudo rm -rf /home/rwintgen/data

fclean:
	@docker system prune -af

.PHONY: all re down clean fclean