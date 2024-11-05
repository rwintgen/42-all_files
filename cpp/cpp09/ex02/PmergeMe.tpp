/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:26:29 by romain            #+#    #+#             */
/*   Updated: 2024/11/05 15:18:52 by rwintgen         ###   ########.fr       */
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
		return ;

	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		if (container[i] > container[i + 1])
			std::swap(container[i], container[i + 1]);
	}

	for (size_t i = 2; i < container.size(); i += 2)
	{
		int		key = container[i];
		size_t	j = i;
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


// Copilot implementation:


// template <typename T>
// void fordJohnsonSort(std::vector<T> &container);

// template <typename T>
// void mergeInsertionSort(std::vector<T> &container, size_t left, size_t right);

// template <typename T>
// void merge(std::vector<T> &container, size_t left, size_t mid, size_t right);

// template <typename T>
// void fordJohnsonSort(std::vector<T> &container)
// {
//     if (container.size() <= 1)
//         return;

//     mergeInsertionSort(container, 0, container.size() - 1);
// }

// template <typename T>
// void mergeInsertionSort(std::vector<T> &container, size_t left, size_t right)
// {
//     if (left >= right)
//         return;

//     size_t mid = left + (right - left) / 2;

//     mergeInsertionSort(container, left, mid);
//     mergeInsertionSort(container, mid + 1, right);

//     merge(container, left, mid, right);
// }

// template <typename T>
// void merge(std::vector<T> &container, size_t left, size_t mid, size_t right)
// {
//     std::vector<T> leftPart(container.begin() + left, container.begin() + mid + 1);
//     std::vector<T> rightPart(container.begin() + mid + 1, container.begin() + right + 1);

//     size_t i = 0, j = 0, k = left;

//     while (i < leftPart.size() && j < rightPart.size())
//     {
//         if (leftPart[i] <= rightPart[j])
//         {
//             container[k] = leftPart[i];
//             i++;
//         }
//         else
//         {
//             container[k] = rightPart[j];
//             j++;
//         }
//         k++;
//     }

//     while (i < leftPart.size())
//     {
//         container[k] = leftPart[i];
//         i++;
//         k++;
//     }

//     while (j < rightPart.size())
//     {
//         container[k] = rightPart[j];
//         j++;
//         k++;
//     }
// }

// template <typename Container>
// void printContainer(const Container &container)
// {
//     typename Container::const_iterator it;
//     for (it = container.begin(); it != container.end(); ++it)
//     {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;
// }

// #endif // PMERGEME_TPP