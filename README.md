# Minishell
This project was carried out in team with [cfontain](https://github.com/clfontain) who built the lexer and the parser as well as several built-in.
## Summary

Authorized functions for the assignment:  `readline`, `rl_clear_history`, `rl_on_new_line`, `rl_replace_line`, `rl_redisplay`, `add_history`, `printf`, `malloc`, `free`, `write`, `access`, `open`, `read`, `close`, `fork`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `sigaction`, `sigemptyset`, `sigaddset`, `kill`, `exit`, `getcwd`, `chdir`, `stat`, `lstat`, `fstat`, `unlink`, `execve`, `dup`, `dup2`, `pipe`, `opendir`, `readdir`, `closedir`, `strerror`, `perror`, `isatty`, `ttyname`, `ttyslot`, `ioctl`, `getenv`, `tcsetattr`, `tcgetattr`, `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`

Code written in accordance with **42 C** coding style.

Minishell is a minimalist Linux Shell written in C able to handle the following features:
- pipes
- redirections such as >, <, and >>
- heredocs with expand option
- command with arguments
- environment variables
---
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
We used a linked list and a lexer to build tokens that we then sent to a parser. The ouput of the parser is a command tab that can be executed accordingly.
The environment is a linked list that allows us to add and remove variables easily. This linked list is converted to a table that can be sent to the execution functions.

This project was a great opportunity to better understand the shell, and to discover how parent and child process work as well as fds and environment of execution.
