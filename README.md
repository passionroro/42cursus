# My school projects !

Hi, I'm Romain! I'm a young student in computer science at **42lausanne**, a programming school opened in 2021 in Lausanne (Switzerland).\
This GitHub gathers all the projects I did, in order, with the grade I got.\
Feel free to have a look at my code, but please be indulgent, it's the first time I code :)\
**Check [so_long](https://github.com/passionroro/42cursus-so_long), it's my favorite project so far!**
> If you are another student of 42, look at your own risk...

## Projects overview

|PROJECT	|GRADE	|NOTIONS	|
|-----------|-------|-----------|
|_00_
|[libft](https://github.com/passionroro/42cursus-libft)							|`115/100`	|C basics, Rigor	|
|_01_																						 
|[Born2beroot](https://github.com/passionroro/42cursus-Born2beroot)				|`100/100`	|Network & system administration	|
|[ft_printf](https://github.com/passionroro/42cursus-ft_printf)					|`100/100`	|C, Unix, Algorithms	|
|[get_next_line](https://github.com/passionroro/42curses-get_next_line)			|`105/100`	|C, Unix, Algorithms	|
|_02_          ||
|[so_long](https://github.com/passionroro/42cursus-so_long)						|`120/100`	|Graphics	|
|[minitalk](https://github.com/passionroro/42cursus-minitalk)					|`109/100`	|Unix, server-client communication	|
|[push_swap](https://github.com/passionroro/42cursus-push_swap)					|`86/100`	|Algorithms	|
|_03_          ||
|[philosophers](https://github.com/passionroro/42cursus-philosophers)					|`in progress`	|Imperative programming		|
|[minishell](https://github.com/passionroro/42cursus-minishell)					|`in progress`	|Unix		|


## What are these projects ?

At School 42, we learn by project, with no teachers, no classes, and no schedule.\ 
The projects you see above are ordered from the easiest to the most difficult, they are kind like our "classes". It is thanks to these projects that we learn the essential notions of programming :)\
I made the choice to detail only the projects that I think are important to the curriculum, but if you have any question about a project, don't hesitate to contact me !

## Try them !!

If you want, you can try these projects, all you need is a computer and an internet connection :)

1) **Set up your environement**\
First, you need to open a Terminal.
	- on macOS/Linux, simply open `Terminal`
	- on Windows, you may wanna install a Unix environment. I would personnaly recommend installing Ubuntu from the Microsoft Store, but you can install any IDE (integrated development environment) such as Visual Studio Code, CLion, Sublime Text.
		- open Microsoft Store
		- install **Ubuntu**
		- open it

2) **Packet installation**\
Once your terminal is open, you will have to install some packets to run the programs.\
\
**Installing git**\
git will allow you to copy my repository (my project) into your environment. This way you will be able to look at the code, run it, edit it, test it... :)\
In your terminal, run the commands : 
 - `sudo apt update`
 - `sudo apt install git-all`\
> (if you have any issues with `sudo`, look on the internet I'm sure you will find an answer <3)

**Installing gcc**\
GCC is a compiler that will allow you to, you guessed it, compile the programs.\
In your terminal, run the commands : 
 - `sudo apt update`
 - `sudo apt install build-essential`

3) **Let's code**\
You are now ready to code ! You can look at my projects and choose one that you might interest you.\
First, head into the repository of your choise ([so_long](https://github.com/passionroro/42cursus-so_long) for example).\
You will find a guide to help you copy the code into your computer and run it.\
If the repository doesn't have any guide, run the following commands :\
 - copy the URL of the repository (for example, https://github.com/passionroro/42cursus-so_long)
 - `git clone <URL> *the name of your choice*`
 - `cd *the name of your choice*`
> What you did here is, you used `git clone` to copy the project into your computer, and you used `cd` to *change directory* into the project.

You can now list all the  project files using `ls -la`\
If there is a `Makefile`, run the commande `Make`. This should compile all the files you need to run the program.\
In case there is no Makefile, you sould use `gcc` (remember the second packet we installed ?)\
 - `gcc -Wall -Werror -Wextra *.c`
 - `./a.out`
> Here you compiled using gcc, that is you turned lines of code into something the computer can *run*. After compiling all the files that end with ".c", the compiler created an executable file, called *a.out*. Running `./a.out` will execute the program.

**And we are done ! Congrats <3333**
