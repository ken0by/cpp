/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:19:52 by rofuente          #+#    #+#             */
/*   Updated: 2024/04/02 17:46:36 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
		{
			for (size_t j = 0; j < std::strlen(argv[i]); ++j)
				argv[i][j] = toupper(argv[i][j]);
			std::cout << argv[i];
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
