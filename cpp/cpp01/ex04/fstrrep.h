/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstrrep.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:21:13 by romain            #+#    #+#             */
/*   Updated: 2024/07/25 17:34:34 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FSTRREP_H
# define FSTRREP_H

# include <string>
# include <iostream>
# include <fstream>

# define ERROR -1
# define SUCCESS 0

# define ERR_ARGC "Usage: ./fstrrep [filename] [s1] [s2]"
# define ERR_INFILE "Error: cannot open infile"
# define ERR_OUTFILE "Error: cannot open outfile"

typedef enum	e_open
{
	OPEN,
	CREATE
}				t_open;

int		openFile(const std::string &filename, int flag, std::ifstream &infile, std::ofstream &outfile);
void	strReplace(std::string &str, const std::string &toRep, const std::string &repBy);
int		printErr(std::string err);


#endif