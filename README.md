## 🖥️ General Information

The aim of this project is sort a list as efficiently as possible using a set limited instructions. 

### Instructions 

**SA or SB** → Will swap the first and second element of list a or list b.

**PA OR PB** → Will push the first element of list a onto list b or the first element of list b onto list a.

**RA or RB** → Will rotate list a or b to the top. First element becomes the last. 

**RRA or RRB** → Will rorate list a or b to the the bottom. Last element becomes the first. 

## 📌 File Organisation

In order to materialize the list to sort, I used the linked list data structure. Here are the contents of the data structure.

```
typedef struct s_stack
{
	int				content;
	int				pos;
	int				push_price;
	bool			cheapest;
	bool			high_median;
	struct s_stack	*target;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;
```
The files the parse arguments and allocate linked list are :

- error_check.c

- ft_init_stack.c

The files to initialize the linked list are : 

- init_nodes.c

-init_nodes_b.c

At first, I implemented the different sorting instructions in the corresponding files :
- swap.c

- push.c
  
- rotate.c

- reverse_rotate.c

Lastly the files that implement the sorting algorithm are : 

- push_swap.c

- sorting.c

## 📂 Installation
The repository contains all the needed libraries to work under Linux. Clone the project into your working directory.
```
git clone <repository_url>
```

Use the make command inside the repository
```
make
```

Run the programm with the following arguments
```
./push_swap [number 1] [number 2] .... [number n]
```

### Testing the Algorithm

The aim of this project was to be able to sort large lists of numbers but it is too complicated and tiring to type 100, 500, 10000 numbers to test the program. 

Hence, there is a **test** rule in the Makefile that generates random numbers between 0 and 5000, launches **push_swap**, uses the checker to see if the list is sorted and counts the number of instructions that were necessary to sort the list. 

```
test :		$(NAME)
			$(eval ARG = $(shell shuf -i 0-5000 -n $(ARG)))
			./push_swap $(ARG) | ./checker_linux $(ARG)
			@echo -n "$(BLUE)Instructions: "
			@./push_swap $(ARG) | wc -l
```

You can also add valgrind to the tester to make sure you don't have memory leak. 

Don't forget to define ARG.

```
ARG			= $(filter-out $@,$(MAKECMDGOALS))
```

As an example, if you want to use this rule to test your algorithm with 500 randomly generated numbers, type :
```
make test 500
```

## 👓 Visualize the algorithm

Here is a screenrecording of how the algorithm I choose acts on the list. 

<div align="center">
  <img src="https://github.com/lgernido/push_swap/blob/main/Visualizer.gif?raw=true" alt="Visualizer" />
</div>

## :book: Ressources 

🇫🇷 

Comprendre les algorithmes de tri en 7 minutes - https://www.jesuisundev.com/comprendre-les-algorithmes-de-tri-en-7-minutes/ 

:uk: 

Understand sorting algorithms and time complexity - https://www.youtube.com/watch?v=UqmKiz2P0Lw 
