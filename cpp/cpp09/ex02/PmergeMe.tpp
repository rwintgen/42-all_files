/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:26:29 by romain            #+#    #+#             */
/*   Updated: 2024/09/09 12:51:44 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Container>
void convertToContainer(const std::string &input, Container &container)
{
	std::istringstream	iss(input);
	std::string			c;

	while (iss >> c)
	{
		try
		{
			int number = std::stoi(c);
			container.push_back(number);
		}
		catch (const std::invalid_argument &e)
		{
			std::cerr << "Invalid input: " << c << " is not a valid integer." << std::endl;
		}
		catch (const std::out_of_range &e)
		{
			std::cerr << "Invalid input: " << c << " is out of range." << std::endl;
		}
	}
}

template <typename Container>
void fordJohnsonSort(Container &container)
{
	if (container.size() <= 1)
		return;

	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		if (container[i] > container[i + 1])
			std::swap(container[i], container[i + 1]);
	}

	for (size_t i = 2; i < container.size(); i += 2)
	{
		int key = container[i];
		size_t j = i;
		while (j > 0 && container[j - 1] > key)
		{
			container[j] = container[j - 1];
			j--;
		}
		container[j] = key;
	}

	for (size_t i = 1; i < container.size(); i += 2)
	{
		int key = container[i];
		size_t j = i;
		while (j > 0 && container[j - 1] > key)
		{
			container[j] = container[j - 1];
			j--;
		}
		container[j] = key;
	}
}

template <typename Container>
void printContainer(const Container &container)
{
	typename Container::const_iterator	it;
	for (it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
