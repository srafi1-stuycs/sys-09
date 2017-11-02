ls: all_da_stuff.c
	gcc -o ls all_da_stuff.c
run: ls
	./ls
clean: 
	rm ls
