#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>


int main(int argc, char *argv[])
{
	FILE *fp;
	char *writefile;
	char *writestr;

	/* open connection */
	openlog("writer", LOG_PID|LOG_CONS, LOG_USER);

	// check the arguments
	if (argc != 3)
	{
		syslog(LOG_ERR, "Error: Two agrments are required.\n  \
				Usage: %s <File Path> <text string to write> \n", argv[0]);
		closelog();
		return 1;
	}	
	writefile = argv[1];
	writestr = argv[2];

	syslog(LOG_DEBUG, "writing %s to %s", writestr, writefile);

	fp = fopen(writefile, "w");
	if (fp == NULL)
	{
		syslog(LOG_ERR, "Error: Failed to open file %s for writing.", writefile);
		closelog();
		return 1;
	}

	if (fputs(writestr, fp) == EOF)
	{
		syslog(LOG_ERR, "Error: Failed to write to the file %s.", writefile);
		fclose(fp);
		closelog();
		return 1;
	}

	fclose(fp);
	closelog();

	return 0;
}

