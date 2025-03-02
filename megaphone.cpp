# include <iostream>

int is_char(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int main(int ac, char **av)
{
	int i = 1;
	int j = 0;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (is_char(av[i][j]))
			{
				if (is_lower(av[i][j]))
					std::cout << (char)(av[i][j] - 32);
				else
					std::cout << av[i][j];
			}
			else
				std::cout << av[i][j];
			j++;
		}
		if (i + 1 < ac)
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return (0);
}