/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:26:29 by romain            #+#    #+#             */
/*   Updated: 2024/11/26 12:45:29 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// converts integers from a std::string to an instance of
// the templated container passed as parameter
template <typename Container>
void	convertToContainer(const std::string &input, Container &container)
{
	std::istringstream	iss(input);
	std::string			c;

	while (iss >> c)
	{
		int number = PmergeMe::stringToInt(c);
		container.push_back(number);
	}
}

// prints all the elements of the instance passed 
// as parameter in the console
template <typename Container>
void	printContainer(const Container &container)
{
	typename Container::const_iterator	it;

	for (it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// creates an populates an array of templated containers,
// each conatining 2 elements ("pairs")
template <typename Container>
std::vector<Container>	createPairs(Container &numbersArray)
{
	std::vector<Container>	pairsArray;
	Container				tmpArray;

	for (typename Container::iterator it = numbersArray.begin(); it != numbersArray.end(); ++it)
	{
		int		value = *it;
		size_t	tmpLen = tmpArray.size();

		if (tmpLen == 0)
			tmpArray.push_back(value);
		else if (tmpLen == 1)
		{
			tmpArray.push_back(value);
			pairsArray.push_back(tmpArray);
			tmpArray.clear();
		}
		else if (pairsArray.size() * 2 == numbersArray.size() - 1)
		{
			Container soloValue(1, value);
			pairsArray.push_back(soloValue);
		}
	}

	return (pairsArray);
}

// for each pair int the pair array pairsArray,
// sets the biggest element of each pair in position [1]
template <typename Container>
std::vector<Container>	sortPairs(std::vector<Container> &pairsArray)
{
	for (typename std::vector<Container>::iterator it = pairsArray.begin(); it != pairsArray.end(); ++it)
	{
		Container	&currentPair = *it;

		if (currentPair.size() == 2 && currentPair[0] > currentPair[1])
			std::swap(currentPair[0], currentPair[1]);
	}
	return (pairsArray);
}

// nserts a pair into the array of sorted pairs at 
// the correct position by comparing the biggest element
// of the pair we want to insert VS the one of each pair
template <typename Container>
void	insert(Container pair, std::vector<Container> &pairsArray, int len)
{
	if (len < 0)
		pairsArray[0] = pair;
	else if (pair[1] >= pairsArray[len][1])
	{
		if (len == static_cast<int>(pairsArray.size()) - 1)
			pairsArray.push_back(pair);
		else
			pairsArray[len + 1] = pair;
	}
	else
	{
		if (len == static_cast<int>(pairsArray.size()) - 1)
			pairsArray.push_back(pairsArray[len]);
		else
		{
			pairsArray[len + 1] = pairsArray[len];
			insert(pair, pairsArray, len - 1);
		}
	}
}

// sorts the array of pairs using insertion sort
// based on the largest element of each pair
template <typename Container>
void	insertSortPairs(std::vector<Container> &pairsArray, int len)
{
	if (len < 1)
		return ;

	insertSortPairs(pairsArray, len - 1);
	insert(pairsArray[len], pairsArray, len - 1);
}

// sorts the vector of pairs by the largest element of each pair
template <typename Container>
void	sortByBiggestElem(std::vector<Container> &sortedPairsArray)
{
	size_t	len = sortedPairsArray.size();

	insertSortPairs(sortedPairsArray, len - 1);
}

// returns the nth Jacobsthal number
static inline int	jacobsthal(int n)
{
	if (n == 0 || n == 1)
		return (n);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

// returns a sequence of Jacobsthal numbers
// up to the length (size) of the input container,
template <typename Container>
Container	getJacobSequence(const Container &array)
{
	int			len = array.size();
	Container	resultSeq;
	int			jacob_index = 3;

	while (jacobsthal(jacob_index) < len - 1)
	{
		resultSeq.push_back(jacobsthal(jacob_index));
		jacob_index++;
	}

	return (resultSeq);
}

// returns a sequence of elements from the 
// sorted pairs array using the Jacobsthal sequence
template <typename Container>
Container	createJacobSeq(std::vector<Container> &SPA, int straggler)
{
	Container	seq;
	Container	pend;

	// separates the integers of each pair into seq (largest) and pend(smallest)
	for (typename std::vector<Container>::iterator it = SPA.begin(); it != SPA.end(); ++it)
	{
		Container	&pair = *it;

		// if (pair.size() < 2)
		// {
		// 	// DEBUG
		// 	std::cerr << "Error: Pair does not contain enough elements." << std::endl;
		// 	continue ;
		// }

		seq.push_back(pair[1]);
		pend.push_back(pair[0]);
	}

	// // DEBUG
	// if (pend.empty()) {
	// 	std::cerr << "Error: Pend is empty." << std::endl;
	// 	return seq;
	// }

	seq.insert(seq.begin(), pend[0]);

	Container	indexSequence(1, 1);
	Container	jacobSeq = getJacobSequence(pend);
	int			last = 0;
	int			i = 1;

	while (i <= static_cast<int>(pend.size()))
	{
		int	item;

		if (!jacobSeq.empty() && last != 1)
		{
			// if (jacobSeq[0] - 1 >= static_cast<int>(pend.size()) || jacobSeq[0] - 1 < 0)
			// {
			// 	// DEBUG
			// 	std::cerr << "Error: JacobSeq index out of bounds." << std::endl;
			// 	break ;
			// }
			indexSequence.push_back(jacobSeq[0]);
			item = pend[jacobSeq[0] - 1];
			jacobSeq.erase(jacobSeq.begin());
			last = 1;
		}
		else
		{
			if (std::find(indexSequence.begin(), indexSequence.end(), i) != indexSequence.end())
			{
				i++;
				continue ;
			}
			// if (i - 1 >= static_cast<int>(pend.size()) || i - 1 < 0)
			// {
			// 	// DEBUG
			// 	std::cerr << "Error: Index out of bounds." << std::endl;
			// 	break ;
			// }
			item = pend[i - 1];
			indexSequence.push_back(i);
			last = -1;
			i++;
		}

		typename Container::iterator	insert = std::upper_bound(seq.begin(), seq.end(), item);
		seq.insert(insert, item);
	}

	if (straggler != -1)
	{
		typename Container::iterator	insert = std::upper_bound(seq.begin(), seq.end(), straggler);
		seq.insert(insert, straggler);
	}

	return (seq);
}

// sorts the input container using the Ford-Johnson sorting algorithm
template <typename Container>
void	fordJohnsonSort(Container &numbersArray)
{
	int	straggler = -1;

	if (numbersArray.size() % 2 == 1)
	{
		straggler = numbersArray.back();
		numbersArray.pop_back();
	}

	// if (numbersArray.empty())
	// {
	// 	// DEBUG
	// 	std::cerr << "Error: numbersArray is empty after removing straggler." << std::endl;
	// 	return ;
	// }

	std::vector<Container> pairsArray = createPairs(numbersArray);
	std::vector<Container> sortedPairsArray = sortPairs(pairsArray);

	sortByBiggestElem(sortedPairsArray);
	numbersArray = createJacobSeq(sortedPairsArray, straggler);
}
