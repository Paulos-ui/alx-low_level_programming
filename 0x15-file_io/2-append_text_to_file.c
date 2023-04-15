#include "main.h"
/**
 * append_text_to_file - This function adds text at EOF
 * @filename: name of the file to append data to.
 * @text_content: data to append to file
 * Return: 1 if succesfull else -1 on err
 */
int append_text_to_file(const char *filename, char *text_content)
{
int open_file;
	int write_file;
	int lent_prg = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (lent_prg = 0; text_content[lent_prg];)
			lent_prg++;
	}

	open_file = open(filename, O_WRONLY | O_APPEND);

	write_file = write(open_file, text_content, lent_prg);

	if (open_file == -1 || write_file == -1)
	{
		return (-1);
	}

	close(open_file);

	return (1);
}
