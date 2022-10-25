# Minishell
## Description
Minishell is a minimalist Linux Shell written in C able to handle the following features:
- pipes
- redirections
- heredocs
- command with arguments
- environment variables
We implemented the single quote and double quote management, however, it does not interpret unclosed quotes or special characters such as \ (backslash) or ; (semicolon).
## Built-in
We implemented the following built-in:
- cd with absolute and relative path or no argument
- echo with option -n
- pwd without option
- env without argument or option
- export without option
- unset without option

## Method
We used a linked list and a lexer to build token that we then sent to a parser. The ouput of the parser is a command tab that can be executed accordingly.
The environment is a linked list that allow us to add and remove variables easily. This linked list is converted to a table that can be sent to the execution functions.

This project was a great opportunity to better understand the shell, and to discover how parent and child process works as well as fds and environment of execution.
