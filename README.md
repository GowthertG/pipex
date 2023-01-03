# pipex

ressources:
  https://vanilla-leader-451.notion.site/PIPEX-c10e5f09840a46d7b987c9bdf818c95c

The purpose of this project is the discovery in detail UNIX mechanism - `pipe`.

### Discription of mandatory part
The program `pipex` should repeat the behaviour of the next shell command
```bash
$> < file1 cmd1 | cmd2 > file2
```
and looks like this:
```bash
$> ./pipex file1 cmd1 cmd2 file2
```
All errors like: wrong commands,  permission to files and etc, need be handle.
### Discription of bonus part
Program need handle multiple pipes
```bash
$> < file1 cmd1 | cmd2 | cmd3 | ... | cmdn > file2

$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
$> ./pipex here_doc LIMITER cmd1 cmd2 file2
```

### Evaluated by moulinette
