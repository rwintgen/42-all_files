/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:13:19 by romain            #+#    #+#             */
/*   Updated: 2024/09/26 14:57:28 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <stdexcept>

class Zombie
{
    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);

        void    announce(void);
        void    setName(std::string name);

    private:
        std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif