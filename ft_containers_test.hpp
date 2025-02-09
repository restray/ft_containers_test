/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers_test.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:28:54 by charles           #+#    #+#             */
/*   Updated: 2022/05/18 12:03:57 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_TEST_HPP
# define FT_CONTAINERS_TEST_HPP

# include <iostream>
# include <string>
# include <algorithm>

# include <cstdlib>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>

# ifdef USE_STD
#  define NAMESPACE_USED std
#  define NAMESPACE_USED_STR "std"
#  include <vector>
#  include <stack>
# else
#  define NAMESPACE_USED ft
#  define NAMESPACE_USED_STR "ft"
#  include "vector.hpp"
#  include "stack.hpp"
# endif

static pid_t testSegvPid;
extern std::string testName;
extern std::string testContainer;

#include <iostream>
#include <ctime> // time_t
#include <cstdio>

# define SANDBOX(x) do {             \
    testSegvPid = fork();            \
    if (testSegvPid == -1) abort();  \
    if (testSegvPid == 0) {          \
        do { (void)(x); } while(0);  \
        exit(EXIT_SUCCESS);          \
    }                                \
    wait(&testSegvPid);              \
} while(0)

# define ASSERT(x) do {                                                         \
    SANDBOX(x);                                                                 \
    if (!WIFEXITED(testSegvPid)) log_tester("[FAIL SEGV  ] ", __FILE__, __LINE__, #x); \
    else if (!(x))               log_tester("[FAIL ASSERT] ", __FILE__, __LINE__, #x); \
    else                         log_tester("[PASS       ] ", __FILE__, __LINE__, #x); \
} while(0)

# define TEST_SEGV(x) do {                                                      \
    SANDBOX(x);                                                                 \
    if (!WIFEXITED(testSegvPid)) log_tester("[FAIL SEGV  ] ", __FILE__, __LINE__, #x); \
    else                         log_tester("[PASS       ] ", __FILE__, __LINE__, #x); \
} while(0)

/*
** log.cpp
*/

void log_tester(const std::string& prefix,
         const std::string& filename,
         int lineNum,
         const std::string& code);

/*
** vector_test.cpp
*/

void vectorTest();

/*
** stack_test.cpp
*/

void stackTest();

#endif
