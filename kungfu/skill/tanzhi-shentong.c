// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// 弹指神通

#include <ansi.h>

inherit SKILL;

string *xue_name = ({ 
        "劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
        "幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",
});

string *action_finger = ({
        "$N中指微屈，突然弹出，一式「指点江山」，一缕劲风直袭$n的$l",
        "$N左掌在身前一划，右手突然穿出，中指微弹，「如来神指」！直袭$n的$l",
        "$N右臂挥动，中指连弹，在身前划了一道弧线，正是「一衣带水」，划向$n的前胸",
        "$N跃起在半空，双手急挥，中指连弹，「弹指惊雷」铺天盖地般向$n涌去",
});

string *action_throwing = ({
        "$N中指微屈，突然弹出，一式「指点江山」，$w破空之声甚厉，直袭$n的$l",
        "$N左掌在身前一划，右手突然穿出，中指微弹，「如来神指」！$w呼啸着直袭$n的$l",
        "$N右臂挥动，中指连弹，数个$w在身前划了一道弧线，正是「一衣带水」，划向$n的前胸",
        "$N跃起在半空，双手急挥，中指连弹，「弹指惊雷」弹出铺天盖地的$w，向$n涌去",
});

int valid_enable(string usage) { return usage == "finger" || usage == "throwing" || usage == "parry"; }

int valid_combine(string combo) { return combo == "lanhua-shou"; }
int double_attack() { return 1; } 

int valid_learn(object me)
{
        object weapon;

        if ((int)me->query("int") < 28)
                return notify_fail("你若有所悟，然而总是有点不明白。\n");

        if (weapon = me->query_temp("weapon"))
                if ((string)weapon->query("skill_type") != "throwing")
                        return notify_fail("学弹指神通必须空手或手持暗器。\n");
                        
        if (me->query("max_neili") >= 1000) return 1;
        
        if ((int)me->query_skill("bibo-shengong", 1) < 70)
                return notify_fail("你的碧波神功火候不够，无法学弹指神通。\n");
                
        if (me->query_skill_mapped("force") != "bibo-shengong")
                return notify_fail("修习弹指神通必须有碧波神功配合。\n");
                
        if ((int)me->query("max_neili") < 200)
                return notify_fail("你的内力太弱，无法练弹指神通。\n");
                
        return 1;
}

mapping query_action(object me, object weapon)
{
        //int i, level;
        int level;

        level   = (int) me->query_skill("tanzhi-shentong", 1);
        
        if (random(level) > 100 && me->query_skill("force") > 120 
        &&  me->query("neili") > 200) 
        {
                me->add("neili", -50);
                if (! weapon)
                        return ([
                                "action": HBRED "$N一声断喝，只听“嗤嗤”之声连响，无数道劲风从四面八方袭向$n" NOR,
                                "force" : 400,
                                "attack": 200,
                                "dodge" : 100,
                                "parry" : 100,
                                "damage_type": "刺伤",
                        ]);
                else
                        return ([
                                "action": HBRED "$N一声断喝，只听“嗤嗤”之声连响，无数" + weapon->query("name") + HBRED"从四面八方袭向$n" NOR,
                                "damage": 160,
                                "attack": 200,
                                "dodge" : 100,
                                "parry" : 100,
                                "damage_type": "刺伤",
                                "post_action": (:call_other, WEAPON_D, "throw_weapon":)
                ]);
        }

        if (! weapon) 
        {
                return ([
                        "action": action_finger[random(sizeof(action_finger))],
                        "force" : 340 + random(50),
                        "attack": 70 + random(10),
                        "dodge" : 70 + random(10),
                        "parry" : 70 + random(10),
                        "damage_type" : "刺伤",
                ]);
        } else
        {
                return ([
                        "action": action_throwing[random(sizeof(action_throwing))],
                        "damage" : 140 + random(30),
                        "attack": 80 + random(10),
                        "dodge" : 80 + random(10),
                        "parry" : 70 + random(10),
                        "damage_type" : "刺伤",
                        "post_action": (:call_other, WEAPON_D, "throw_weapon":)
                ]);        
        }     
}

int practice_skill(object me)
{
        object weapon;

        if (weapon = me->query_temp("weapon"))
                if ((string)weapon->query("skill_type") != "throwing")
                        return notify_fail("练弹指神通必须空手或手持暗器。\n");
                        
        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力太低了。\n");
                
        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练弹指神通。\n");
                
        me->receive_damage("qi", 70);
        me->add("neili", -70);
        
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tanzhi-shentong/" + action;
}

mixed hit_ob(object me, object victim, int damage)
{
        string name, weapon;
        mixed result;
        name = xue_name[random(sizeof(xue_name))];
    
        if (victim->is_busy()) return 0;
        
        if (! objectp(weapon = me->query_temp("weapon"))) 
        {
                if ((me->query("neili") > 200) && me->query_skill("tanzhi-shentong", 1) > 100 
                &&  me->query("max_neili") > 1200)
                {
                        victim->start_busy(3);
                        me->add("neili", -30);
                        if (victim->query("neili") <= (damage/2 + 30))
                                victim->set("neili",0);
                        else
                                victim->add("neili", -damage / 2 + 30);
                        return HIR "$N突然伸指，连点$n"HIC"「"+name+"」"HIR"，$n脸色陡然变得苍白，内息直泄！\n" NOR;
                } 
        } else 
        {
                if ((me->query("neili") > 200) && me->query_skill("tanzhi-shentong", 1) > 60)
                {
                        victim->start_busy(2);
                        me->add("neili", -30);
                        result = ([ "damage" : damage ]);
                        result += ([ "msg" : HIR "$n被$N的暗器打中"HIC"「"+name+"」"HIR"，内息大乱！\n" NOR]);
                        
                        return result;
                }   
        }
 
}

int query_effect_parry(object attacker, object me)
{
        object weapon;
        int lvl;

        if (objectp(weapon = me->query_temp("weapon")))
                if ((string)weapon->query("skill_type") != "throwing")
                        return 0;

        lvl = me->query_skill("tanzhi-shentong", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}

/*
mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping prepare;
        string attack_skill;
        mixed result;
        int ap, dp, mp;

        if ((int)me->query_skill("tanzhi-shentong", 1) < 100 
        ||  ! living(me) || me->query_temp("weapon"))
                return;

        mp = ob->query_skill("martial-cognize", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("parry", 1) / 2 +
             me->query_skill("tanzhi-shentong", 1);
             
        if (objectp(weapon = ob->query_temp("weapon"))) 
                attack_skill = weapon->query("skill_type");
        else
        {
                prepare = ob->query_skill_prepare();
                if (! prepare) prepare = ([]);
                else if (sizeof(prepare) == 0)  attack_skill = "unarmed";
                else if (sizeof(prepare) == 1)  attack_skill = (keys(prepare))[0];
                else if (sizeof(prepare) == 2)  attack_skill = (keys(prepare))[ob->query_temp("action_flag")];
        }
        attack_skill = ob->query_skill_mapped(attack_skill);
        
        if (ap / 2 + random(ap) < dp && stringp(attack_skill))
        {
                result = ([ "damage": -damage ]);
                // 去掉所有的伤害写法
                if (objectp(weapon = ob->query_temp("weapon")))
                {
                        result += (["msg" : HIC "$n" HIC "伸指一弹，嗤的一声轻响，一股细细的劲力激射出去，"
                                                "登时将" + weapon->name() + HIC"上所附内劲尽数抵销，"
                                                        "化解了这招" + to_chinese(attack_skill) + "。\n" NOR]);
                }
                else    result += (["msg" : HIC "$n" HIC "伸指一弹，嗤的一声轻响，一股细细的劲力激射出去，"
                                "这「弹指神通」与$N的「" + to_chinese(attack_skill) + "」斗了个旗鼓相当，"
                                        "谁也没能伤谁。\n" NOR]);
                return  result;
        }
}

*/
