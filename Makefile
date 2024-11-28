#Marica Mihai_312CA
build: star_dust

star_dust: star_dust.c
	gcc -Wall -Wextra star_dust.c -o star_dust

clean: 
	rm -f star_dust