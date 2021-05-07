#pragma once

#include "../list/list.hpp"
#include <list>
#include <vector>


#define OK "\e[0;32mOK\e[0;0m"
#define KO "\e[0;31mKO\e[0;0m"


#define B "\e[0;34m"
#define G "\e[0;32m"
#define R "\e[0;31m"

#define CLEAN "\e[0;0m"
#define PUT_STR(STR) std::cout << STR CLEAN << std::endl