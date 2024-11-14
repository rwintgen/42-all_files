/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:26:29 by romain            #+#    #+#             */
/*   Updated: 2024/11/14 17:28:07 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Container>
void convertToContainer(const std::string &input, Container &container)
{
	std::istringstream	iss(input);
	std::string			c;

	while (iss >> c)
	{
		int	number = PmergeMe::stringToInt(c);
		container.push_back(number);
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

template <typename Container>
std::vector<Container> createPairs(Container &numbersArray)
{
	std::vector<Container>	pairsArray;
	Container				tmpArray;

	for (typename Container::iterator it = numbersArray.begin(); it < numbersArray.end(); it++)
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
			Container	soloValue(1, value);
			pairsArray.push_back(soloValue);
		}
	}

	return (pairsArray);
}

template <typename Container>
std::vector<Container> sortPairs(std::vector<Container> &pairsArray)
{
	for (typename std::vector<Container>::iterator it = pairsArray.begin(); it != pairsArray.end(); it++)
	{
		Container	currentPair = *it;

		if (currentPair.size() == 2 && currentPair[0] > currentPair[1])
			std::swap(currentPair[0], currentPair[1]);
	}
	return (pairsArray);
}

template <typename Container>
void insert(Container pair, std::vector<Container> &pairsArray, int len)
{
	if (len < 0)
		pairsArray[0] = pair;
	else if (pair[1] >= pairsArray[len][1])
	{
		if (len == pairsArray.size() - 1)
			pairsArray.push_back(pair);
		else
			pairsArray[len + 1] = pair;
	}
	else
	{
		if (len == pairsArray.size() - 1)
			pairsArray.push_back(pairsArray[len]);
		else
		{
			pairsArray[len + 1] = pairsArray[len];
			insert(pair, pairsArray, len - 1);
		}
	}
}

template <typename Container>
void insertionSortPairs(std::vector<Container> &pairsArray, int len)
{
    if (len < 1)
        return;
    else
	{
        insertionSortPairs(pairsArray, len - 1);
        insert(pairsArray[len], pairsArray, len - 1);
    }
}

template <typename Container>
void sortByBiggestElem(std::vector<Container> &sortedPairsArray)
{
    size_t	len = sortedPairsArray.size();
	
	// start of recursive mayhem!
    insertionSortPairs(sortedPairsArray, len - 1);
}

static int jacobsthal(int n)
{
    if (n == 0 || n == 1)
        return (n);
    return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

template <typename Container>
Container getJacobSequence(const Container &array)
{
    int			array_len = array.size();
    Container	end_sequence;
    int			jacob_index = 3;

    while (jacobsthal(jacob_index) < array_len - 1)
	{
        end_sequence.push_back(jacobsthal(jacob_index));
        jacob_index++;
    }

    return (end_sequence);
}

template <typename Container>
Container createJacobSeq(std::vector<Container> &SPA, int straggler)
{
    Container	Seq;
    Container	pend;

    for (typename std::vector<Container>::iterator it = SPA.begin(); it != SPA.end(); ++it)
    {
        Container &pair = *it;

        Seq.push_back(pair[1]);
        pend.push_back(pair[0]);
    }

    Seq.insert(Seq.begin(), pend[0]);

    Container	indexSequence(1, 1);
    Container	jacobSeq = getJacobSequence(pend);
    int			jacobindex = 3;
    int			last = 0;
    int			i = 0;

    while (i <= pend.size())
	{
        int	item;

        if (!jacobSeq.empty() && last != 1)
		{
            indexSequence.push_back(jacobSeq[0]);
            item = pend[jacobSeq[0] - 1];
            jacobSeq.erase(jacobSeq.begin());
            last = 1;
        }
		else
		{
            if (std::find(indexSequence.begin(), indexSequence.end(), i) != indexSequence.end())
                i++;
            item = pend[i - 1];
            indexSequence.push_back(i);
            last = -1;
            i++;
            jacobindex++;
        }

        typename Container::iterator	insert = std::upper_bound(Seq.begin(), Seq.end(), item);
        Seq.insert(insert, item);
    }

    if (straggler != -1)
	{
        typename Container::iterator	insert = std::upper_bound(Seq.begin(), Seq.end(), straggler);
        Seq.insert(insert, straggler);
    }

    return (Seq);
}


template <typename Container>
void fordJohnsonSort(Container &numbersArray)
{
	int	straggler = -1;

	if (numbersArray.size() % 2 == 1)
	{
		straggler = numbersArray.back();
		numbersArray.pop_back();
	}

	std::vector<Container>	pairsArray = createPairs(numbersArray);
	std::vector<Container>	sortedPairsArray = sortPairs(pairsArray);

	sortByBiggestElem(sortedPairsArray);
	numbersArray = createJacobSeq(sortedPairsArray, straggler);
}
