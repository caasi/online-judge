#define LINE_LEN 255

/* get a number before \n */
int get_a_number(int *num)
{
	int count = 0, c;
	char line[LINE_LEN + 1];
	while(count < LINE_LEN)
	{
		c = getchar();
		if(c == '\n' || c == EOF)
			break;
		/* got a number */
		if(count && !isdigit(c))
			break;
		if(isdigit(c))
			line[count++] = c;
	}
	line[count] = '\0';
	if(num)
		*num = atoi(line);
	return line[0];
}
