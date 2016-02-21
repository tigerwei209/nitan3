// meiren-sanzhao.c ��������
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N����΢����������Ť�����㷴�ߣ���$n��С����ȥ��$n������ܣ�\n"
                   "$N˳�Ʒ�������������§ס$nͷ���������ս���׼$n���ģ�һ����ȥ",
        "force" : 70,
        "dodge" : 5,
        "parry" : 10,
        "damage": 100,
        "lvl" : 0,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N�����Ե���$n�������̤ס$N�ĺ�����$N���Դ��������Լ����ؿ����䣬\n"
                   "˳���ڵ���һ�������$n�Ŀ�������������ս�����$n�ĺ���",
        "force" : 80,
        "dodge" : 20,
        "parry" : 20,
        "damage": 120,
        "lvl" : 10,
        "skill_name" : "С�����",
        "damage_type" : "����"
]),
([      "action" : "$N������ǰ���ߣ�˳��һ�������ϵĽ�����$n���ʺ���ȥ",
        "force" : 120,
        "dodge" : 30,
        "parry" : 30,
        "damage": 160,
        "lvl" : 20,
        "skill_name" : "�������",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }

   int valid_combine(string combo) { return combo=="jueming-tui" ; }

int valid_learn(object me)
{
        if (me->query("gender") != "Ů��")
                return notify_fail("�㲻��Ů�ӣ�����ô��ѧ�����������أ�\n");
        if (me->query_int() < 25)
                return notify_fail("������Բ������޷�ѧ�������С�\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷�ѧ�������С�\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("meiren-sanzhao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        int level;

        if( (int)me->query("jingli") < 30 || (int)me->query("jing") < 30 )
                return notify_fail("��ľ���̫�ã��޷�������ϰ��\n");

        if( (int)me->query("neili") < 200)
                return notify_fail("��������������������С�\n");


        level = (int)me->query_skill("meiren-sanzhao", 1);
        if( level < 30 )
                return notify_fail("����������е����ջ�������\n");

        if( level > (int)me->query_skill("sword", 1))
                return notify_fail("�������������Ҳ������ȥ�ˡ�\n");

        me->add("jingli", -30);
        me->receive_damage("jing", 30);
        me->add("neili",-30);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if((damage_bonus/2) > victim->query_str()&& 
               !victim->query_temp("boduo")){
                victim->receive_wound("qi", (damage_bonus - 100) / 2 );
                victim->add_temp("boduo",1);                return HIW "ֻ����һ������������"BLINK"��һ�а��ᣡ\n" NOR;
        }
        if( (damage_bonus/2) > victim->query_str()&& 
                victim->query_temp("boduo")== 1){                victim->receive_wound("qi", (damage_bonus - 90) / 2 );
                victim->add_temp("boduo",1);
                return HIG"ֻ����һ������������"BLINK"�ڶ��а��ᣡ\n" NOR;
        }
        if( (damage_bonus/2) > victim->query_str()&& 
                victim->query_temp("boduo")== 2){                victim->receive_wound("qi", (damage_bonus - 80) / 2 );
                victim->add_temp("boduo",1);
                return HIB "ֻ����һ������������"BLINK"�����а��ᣡ\n" NOR;
        }
        if( (damage_bonus/2) > victim->query_str()&& 
                victim->query_temp("boduo")== 3){       
                victim->receive_wound("qi",(damage_bonus - 70) / 2 );
                victim->add_temp("boduo",1);
                return HIY"ֻ����һ������������"BLINK"���ĸа��ᣡ\n" NOR;
        }
        if( (damage_bonus/2) > victim->query_str() && 
                victim->query_temp("boduo")== 4){
                victim->receive_wound("qi", (damage_bonus - 60) / 2 );
                victim->add_temp("boduo",1);
                return HIC"ֻ����һ������������"BLINK"����а��ᣡ\n" NOR;
        }
        if( (damage_bonus/2) > victim->query_str()&& 
                victim->query_temp("boduo")== 5){
                victim->receive_wound("qi", (damage_bonus - 50) / 2 );
                victim->add_temp("boduo",1);
                return HIR "ֻ����һ������������"BLINK"�����а��ᣡ\n" NOR;
        }
        if( (damage_bonus/2) > victim->query_str()&& 
                victim->query_temp("boduo")== 6){
                victim->delete_temp("boduo");
                return WHT"ֻ����һ������������"BLINK"�ٴΰ��Ὺʼ��\n" NOR;
        }
        
}
string perform_action_file(string action)
{
        return __DIR__"meiren-sanzhao/" + action;
}

