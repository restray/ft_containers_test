/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 21:08:51 by charles           #+#    #+#             */
/*   Updated: 2022/05/18 11:51:41 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers_test.hpp"

std::string testName = "";
std::string testContainer = "";

void log_tester(const std::string &prefix,
                const std::string &filename,
                int lineNum,
                const std::string &code)
{
    std::cout << prefix << "{"
              << testContainer << "} {"
              << ::testName << "} "
              << filename << ':'
              << lineNum
              << " (" << code << ")"
              << std::endl;
}
