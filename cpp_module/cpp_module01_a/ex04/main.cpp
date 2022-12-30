#include <iostream>
#include <fstream>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Error: This program must need ./ex04 filename string1 string2." << std::endl;
		return (1);
	}

	std::string	filename = argv[1];
	std::string	str1 = argv[2];
	std::string	str2 = argv[3];

	std::ifstream fin(filename);

	if (!fin.good() || !fin.is_open())
	{
		std::cout << "Error: Do not stream open of file open." << std::endl;
		return (1);
	}

	std::string	line;
	
	filename.append(".replace");

	std::ofstream fout(filename, std::ios_base::out | std::ios_base::trunc);

	while (std::getline(fin, line))
	{
		for (size_t i = 0; i < line.length() - str1.length(); i++)
		{
			if (str1.compare(line.substr(i, str1.length())) == 0)
			{
				line.erase(i, str1.length());
				line.insert(i, str2);
			}
		}
		fout.write(line.c_str(), line.length());
		if (!fin.eof())
			fout.write("\n", 1);
	}

	fin.close();
	fout.close();

	return (0);
}
