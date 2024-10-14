#ifndef    _TEAM_MANGE_H_			
#define    _TEAM_MANGE_H_

#include "member.h"
#include "attendance.h"
#include <iostream>		
#include <vector>		
#include <string>		
#include <algorithm>

using namespace std;

typedef enum Menu_Options
{
    quit,
    entry_member,    
    remove_member,
    print_members,
    revise_members,
    read_attendence,
    revise_attendence,
    
}Menu_Options;

int Menu_Select(void);
void Menu_Option(int choice);


#endif
