#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int sv;

	int in = open("/etc/passwd", O_RDONLY);
	int out = open("r.txt", O_WRONLY);
	
	int pfd[2];
	pipe(pfd);
	
	if(fork() == 0) //grep
	{
		dup2(in, 0);
		dup2(pfd[1], 1);
		close(pfd[1]);
		close(pfd[0]);
		
		execlp("grep", "grep", "-v", "usr", NULL);
		exit(0);
	}
	else if(fork() == 0) //wc
	{
		dup2(pfd[0], 0);
		dup2(out, 1);
		close(pfd[1]);
		close(pfd[0]);

		execlp("wc", "wc", "-l", NULL);
		exit(0);
	}

	close(pfd[1]);
	close(pfd[0]);
	wait(&sv);
	wait(&sv);
	
	//cat
	execlp("cat", "cat", "r.txt", NULL);
	
	return 0;
}
