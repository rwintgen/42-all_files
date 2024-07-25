/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:13:19 by romain            #+#    #+#             */
/*   Updated: 2024/07/25 13:15:54 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);

        void announce(void);
    private:
        std::string _name;
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif