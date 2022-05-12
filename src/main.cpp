/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:28:20 by charles           #+#    #+#             */
/*   Updated: 2022/05/12 14:08:26 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers_test.hpp"

int main(int argc, char **argv)
{
    std::cout << NAMESPACE_USED_STR << std::endl;
    if (argc == 2)
    {
        std::string option(argv[1]);
        if (option == "vector")
            vectorTest();
        if (option == "stack")
            stackTest();
    }
    else
    {
        vectorTest();
        stackTest();
    }
    return 0;
}
