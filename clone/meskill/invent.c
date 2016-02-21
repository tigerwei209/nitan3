// Copyright (C) 2005, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// invent.c �Դ��书
#include <ansi.h>;

inherit F_DBASE;
inherit F_SAVE;
inherit FORCE;


int check_skill();

mapping *actions;
string skill_name;
void set_skill_name(string skill) { skill_name = skill; }
void set_actions(mapping *action) { actions = action; }
string query_skill_name() { return skill_name; }
mapping *query_actions() { return actions; }
mapping query_action() { return actions[random(sizeof(actions))]; }

string query_save_file() { return DATA_DIR "skill/" + skill_name; }

int save()
{
        if (! stringp(skill_name) || skill_name == "")
                return 0;

        return ::save();
}

int create_skill(string skill)
{
        skill_name = skill;
        
        if (! restore()) 
                return 0;
        else 
        {
                if (check_skill()) 
                        return 1;
                else 
                        return 0;
        }
}

// ����Դ��书������
int check_skill()
{
        if (! pointerp(query("usages")) || sizeof(query("usages")) < 1)
                return 0;
        /*
        if( member_array("force", query("usages")) == -1
                && ( !pointerp(actions) || sizeof(actions) < 1 ) )
                return 0;
        */
        if (! stringp(query("owner")))
                return 0;

        if (! stringp(query("chinese_name")))
                return 0;

        return 1;
}

int valid_enable(string usage)
{
        return member_array(usage, query("usages")) != -1;
}

int valid_learn(object me)
{
        return 1;
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("���״̬̫���ˣ�������" + query("chinese_name") + "��\n");
        me->receive_damage("qi", 30);
        return 1;
}
