/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:17:11 by romain            #+#    #+#             */
/*   Updated: 2024/09/26 15:03:44 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fstrrep.h"

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (printErr(ERR_ARGC));

	std::ifstream infile;
	std::ofstream outfile;

	if (openFile(argv[1], OPEN, infile, outfile) == ERROR \
		|| openFile(argv[1], CREATE, infile, outfile) == ERROR)
		return (1);

	std::string line;
	std::string fileContent;

	while (std::getline(infile, line))
		fileContent += line + "\n";

	strReplace(fileContent, argv[2], argv[3]);
	outfile << fileContent;

	infile.close();
	outfile.close();

	return (0);
}

int	openFile(const std::string &filename, int flag, std::ifstream &infile, std::ofstream &outfile)
{
	if (flag == OPEN)
	{
		infile.open(filename.c_str());
		if (!infile.is_open())
			return printErr(ERR_INFILE);
	}
	else if (flag == CREATE)
	{
		outfile.open((filename + ".replace").c_str());
		if (!outfile.is_open())
			return printErr(ERR_OUTFILE);
	}
	return (SUCCESS);
}

void	strReplace(std::string &str, const std::string &toRep, const std::string &repBy)
{
	if (toRep.empty())
		return ;

	size_t pos = 0;

	while ((pos = str.find(toRep, pos)) != std::string::npos)
	{
		str.erase(pos, toRep.length());
		str.insert(pos, repBy);
		pos += repBy.length();
	}
}

int	printErr(std::string err)
{
	std::cerr << err << std::endl;
	return (ERROR);
}
