int main(int argc, char **argv)
{
	if (argc == 1)
	{
		print(message);
	}
	else
	{
		char *upperMsg = toUpperCase(argv[1]);
		print(upperMsg);
	}
	return (0);
}