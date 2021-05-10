#pragma once

#include "../list/list.hpp"
#include <type_traits>
#include <list>
#include <vector>


#define OK "\e[0;32mOK\e[0;0m"
#define KO "\e[0;31mKO\e[0;0m"


#define B "\e[0;34m"
#define G "\e[0;32m"
#define R "\e[0;31m"
#define LB "\e[0;36m"

#define CLEAN "\e[0;0m"
#define PUT_STR(STR) std::cout << STR CLEAN << std::endl


//
//template <typename T>
//void check_value(typename ft::list<T>::iterator &ft_itb, typename ft::list<T>::iterator &ft_ite, typename std::list<T>::iterator &std_itb, typename std::list<T>::iterator &std_ite, bool &flag);
//
//template <typename T, typename std::enable_if<!std::numeric_limits<T>::is_specialized>::type> >
//void check_value(typename ft::list<T>::iterator &ft_itb, typename ft::list<T>::iterator &ft_ite, typename std::list<T>::iterator &std_itb, typename std::list<T>::iterator &std_ite, bool &flag);