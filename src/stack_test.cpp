/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 14:39:05 by charles           #+#    #+#             */
/*   Updated: 2022/05/12 09:42:48 by tbelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers_test.hpp"
#include <stack>

static void testConstructorDefault()
{
    testName = "Stack.Stack default";

    ft::stack<int>     s1;
    ft::stack<char>    s2;
    ft::stack<char*>   s3;
    ft::stack<char**>  s4;

    ASSERT(s1.size() == 0);
    ASSERT(s2.size() == 0);
    ASSERT(s3.size() == 0);
    ASSERT(s4.size() == 0);

    ASSERT(s1.empty());
    ASSERT(s2.empty());
    ASSERT(s3.empty());
    ASSERT(s4.empty());
}

static void testConstructorCopy()
{
    testName = "Stack.Stack copy";

    ft::stack<int>     s1_copied;
    ft::stack<char>    s2_copied;

    s1_copied.push(1);
    s1_copied.push(2);
    s1_copied.push(3);
    ft::stack<int>     s1(s1_copied);
    ASSERT(s1.size() == 3);
    ASSERT(s1.top() == 3);
    s1.pop();
    ASSERT(s1.top() == 2);
    s1.pop();
    ASSERT(s1.top() == 1);

    s2_copied.push('a');
    s2_copied.push('b');
    ft::stack<char>     s2(s2_copied);
    ASSERT(s2.size() == 2);
    ASSERT(s2.top() == 'b');
    s2.pop();
    ASSERT(s2.top() == 'a');
}

static void testOperatorAssign()
{
    testName = "Stack.operator=";

    ft::stack<int>     s1_copied;
    ft::stack<char>    s2_copied;

    s1_copied.push(1);
    s1_copied.push(2);
    s1_copied.push(3);
    ft::stack<int>     s1 = s1_copied;
    ASSERT(s1.size() == 3);
    ASSERT(s1.top() == 3);
    s1.pop();
    ASSERT(s1.top() == 2);
    s1.pop();
    ASSERT(s1.top() == 1);

    s2_copied.push('a');
    s2_copied.push('b');
    ft::stack<char>     s2 = s2_copied;
    ASSERT(s2.size() == 2);
    ASSERT(s2.top() == 'b');
    s2.pop();
    ASSERT(s2.top() == 'a');
}

static void testTop()
{
    testName = "Stack.top";

    ft::stack<int> s1;

    s1.push(1);
    ASSERT(s1.size() == 1);
    ASSERT(s1.top() == 1);
    s1.push(2);
    ASSERT(s1.size() == 2);
    ASSERT(s1.top() == 2);
    s1.push(3);
    ASSERT(s1.size() == 3);
    ASSERT(s1.top() == 3);
    s1.push(4);
    ASSERT(s1.size() == 4);
    ASSERT(s1.top() == 4);
    s1.push(5);
    ASSERT(s1.size() == 5);
    ASSERT(s1.top() == 5);
    s1.push(6);
    ASSERT(s1.size() == 6);
    ASSERT(s1.top() == 6);
}

static void testPush()
{
    testName = "Stack.push";

    ft::stack<int> s1;

    s1.push(1);
    ASSERT(s1.size() == 1);
    ASSERT(s1.top() == 1);
    s1.push(2);
    ASSERT(s1.size() == 2);
    ASSERT(s1.top() == 2);
    s1.push(3);
    ASSERT(s1.size() == 3);
    ASSERT(s1.top() == 3);
    s1.push(4);
    ASSERT(s1.size() == 4);
    ASSERT(s1.top() == 4);
    s1.push(5);
    ASSERT(s1.size() == 5);
    ASSERT(s1.top() == 5);
    s1.push(6);
    ASSERT(s1.size() == 6);
    ASSERT(s1.top() == 6);
}

static void testPop()
{
    testName = "Stack.pop";

    ft::stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.pop();
    ASSERT(s1.size() == 5);
    ASSERT(s1.top() == 5);
    s1.pop();
    ASSERT(s1.size() == 4);
    ASSERT(s1.top() == 4);
    s1.pop();
    ASSERT(s1.size() == 3);
    ASSERT(s1.top() == 3);
    s1.pop();
    ASSERT(s1.size() == 2);
    ASSERT(s1.top() == 2);
    s1.pop();
    ASSERT(s1.size() == 1);
    ASSERT(s1.top() == 1);
    s1.pop();
    ASSERT(s1.size() == 0);
}

static void testOperatorEqual()
{
    testName = "Stack.operator[== !=]";

    ft::stack<int> s1;
    ft::stack<int> s2;

    ASSERT(s1 == s2);
    ASSERT(s2 == s1);
    s1.push(1);
    ASSERT(s1 != s2);
    ASSERT(s2 != s1);
    s2.push(1);
    ASSERT(s1 == s2);
    ASSERT(s2 == s1);
    s2.push(2);
    ASSERT(s1 != s2);
    ASSERT(s2 != s1);
}

static void testOperatorCompar()
{
    testName = "Stack.operator[< > <= >=]";

    ft::stack<char> s1;
    ft::stack<char> s2;
    ft::stack<char> s3;

    s1.push('a');

    s2.push('a');
    s2.push('a');

    s3.push('a');
    s3.push('a');
    s3.push('a');

    ASSERT(s1 < s2);
    ASSERT(s1 < s3);
    ASSERT(s2 > s1);
    ASSERT(s2 < s3);
    ASSERT(s3 > s1);
    ASSERT(s3 > s2);

    ASSERT(s1 <= s1);
    ASSERT(s1 >= s1);
    ASSERT(s2 <= s2);
    ASSERT(s2 >= s2);
    ASSERT(s3 <= s3);
    ASSERT(s3 >= s3);

    ft::stack<char> s4;
    s4.push('a');
    s4.push('b');

    ASSERT(s4 > s1);
    ASSERT(s4 > s2);
    ASSERT(s4 > s3);

    ASSERT(s4 <= s4);
    ASSERT(s4 >= s4);
}

void stackTest()
{
    testContainer = "Stack";

    testConstructorDefault();
    testConstructorCopy();
    testOperatorAssign();

    testTop();
    testPush();
    testPop();

    testOperatorEqual();
    testOperatorCompar();
}
