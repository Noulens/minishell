static void sub_dup2(int zero, int first)

{

dup2(zero, 0);

dup2(first, 1);

}

void child(t_ppxb p, char **argv, char **envp)

{

p.pid = fork();

if (!p.pid)

{

if (p.idx == 0)

sub_dup2(p.infile, p.pipe[1]);

else if (p.idx == p.cmd_nmbs - 1)

sub_dup2(p.pipe[2 * p.idx - 2], p.outfile);

else

sub_dup2(p.pipe[2 * p.idx - 2], p.pipe[2 * p.idx + 1]);