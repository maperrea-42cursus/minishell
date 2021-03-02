# minishell
Creating a simple shell.

## Description
The `minishell` project is part of the cursus at [42](https://42.fr). Its scope is to teach us about files, i/o and processes. The objective is to create a basic bash-like shell with features like redirections, pipes, signals, environement variables, builtins, etc.

## File tree

* `include/` : header files
* `libcarbon/` : submodule to [this](https://github.com/30c27b/libcarbon) library
* `source/` : minishell sources

## Structure

### Module `prompt`
The prompt module will display a prompt then read and return a line written by the user.

**Public methods:**

```c
/*
** @brief Prompts the user with a new shell line and reads the first line of
** input
** 
** @return char* the first line of input from the user
*/
char    *msh_prompt(void);
```

### Module `parser`
TODO

### Module `interpreter`
TODO

### Module `builtins`
TODO

### Module `shared`
TODO

## Authors
* [Matthis Perreaux](https://github.com/maperrea) (maperrea)
* [Alexandre Pelissier](https://github.com/alpeliss) (alpeliss)
* [Antoine Coulon](https://github.com/30c27b) (ancoulon)

## License
This project is distributed under the [ISC license](/LICENSE).
