// qishang-quan.c -七伤拳
// modify by LONELY 2003
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N气凝如山，一式「金戈铁马」，双拳蓄势而发，击向$n的$l",
	"force" : 180,
	"dodge" : 5,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "金戈铁马",
	"damage_type" : "内伤"
]),
([	"action" : "$N身形凝重，劲发腰背，一式「木已成舟」，缓缓向$n推出",
	"force" : 220,
	"dodge" : 5,
	"damage": 15,
	"lvl" : 40,
	"skill_name" : "木已成舟",
        "damage_type" : "内伤"
]),
([	"action" : "$N步伐轻灵，两臂伸舒如鞭，一式「水中捞月」，令$n无可躲闪",
	"force" : 250,
	"dodge" : 15,
	"damage": 20,
	"lvl" : 70,
	"skill_name" : "水中捞月",
        "damage_type" : "内伤"
]),
([	"action" : "$N身形跃起，一式「火海刀山」，双拳当空击下，势不可挡",
	"force" : 290,
	"dodge" : 5,
	"damage": 30,
	"lvl" : 100,
	"skill_name" : "火海刀山",
        "damage_type" : "内伤"
]),
([	"action" : "$N身形一矮，一式「土载万物」，两拳自下而上，攻向$n",
	"force" : 330,
	"dodge" : 10,
	"damage": 45,
	"lvl" : 120,
	"skill_name" : "土载万物",
        "damage_type" : "内伤"
]),
([	"action" : "$N身形一转，一式「阴风惨惨」，攻向$n的身前身后",
	"force" : 350,
	"dodge" : 25,
	"damage": 60,
	"lvl" : 140,
	"skill_name" : "阴风惨惨",
        "damage_type" : "内伤"
]),
([	"action" : "$N移形换位，步到拳到，一式「阳光普照」，四面八方都是拳影",
	"force" : 370,
	"dodge" : 15,
	"damage": 75,
	"lvl" : 150,
	"skill_name" : "阳光普照",
        "damage_type" : "内伤"
]),
([	"action" : "$N长啸一声，向前踏出一步，双拳中宫直进，一式「七者皆伤」，骤然击向$n的前胸",
	"force" : 390,
	"dodge" : 20,
	"damage": 100,
	"lvl" : 160,
	"skill_name" : "七者皆伤",
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练七伤拳必须空手。\n");

	if ((int)me->query_skill("force", 1) < 120)
		return notify_fail("你的内功火候不够，无法学七伤拳。\n");

	if ((int)me->query("max_neili") < 1800)
		return notify_fail("你的内力修为不够，无法练七伤拳。\n");

        if ((int)me->query_skill("cuff", 1) < 120)
                return notify_fail("你的基本拳法火候不够，无法练七伤拳。\n");

        if ((int)me->query_skill("cuff", 1) < (int)me->query_skill("qishang-quan", 1))
                return notify_fail("你的基本拳法水平还不够，无法领会更高深的七伤拳。\n");

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
	level   = (int) me->query_skill("qishang-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 70)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 70)
		return notify_fail("你的内力不够练七伤拳。\n");

	me->receive_damage("qi", 55);
	me->add("neili", -61);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"qishang-quan/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string msg;
        mixed result;
        int lvl;
        int flvl;

        lvl  = me->query_skill("qishang-quan", 1);
        flvl = me->query("jiali");
        if (lvl < 80 || flvl < 10 || ! damage_bonus)
                return;

        if (random(lvl) > 80 && (int)me->query("neili") > 300 &&       
            victim->affect_by("qs_poison",
                              ([ "level" : flvl + random(flvl),
                                 "id"    : me->query("id"),
                                 "duration" : lvl / 100 + random(lvl / 10) ])))
        {
                result = ([ "damage" : damage_bonus ]);
                me->add("neili", -200);
                
                switch(random(7))
                {
                case 0 :
                        msg = MAG"$N凝神定气，使出七伤拳总诀中的「"HIR"损心诀"MAG"」，双拳一股刚猛之力向$n击去。\n"NOR;
                        break;
                case 1 :
                        msg = HIB"$N深吸一口气，左拳再使出七伤拳总诀中的「"HIR"伤肺诀"HIB"」，双拳飘忽不定，$n顿时感觉一股阴柔之力迎面而来。\n"NOR;
                        break;
                case 2 :
                        msg = HIC"$N右拳接着使出七伤拳总诀中的「"HIR"摧肝肠诀"HIC"」，双拳刚中有柔，向$n击去。\n"NOR;
                        break;
                case 3 :
                        msg = HIG"$N凝神定气，使出七伤拳总诀中的「"HIR"藏离诀"HIG"」，双拳柔中有刚，打出一股内缩之力！向$n击去。\n"NOR;
                        break;
                case 4 :
                        msg = HIY"$N凝神定气，使出七伤拳总诀中的「"HIR"精失诀"HIY"」，双拳势如雷霆，将力道直向$n送去。\n"NOR;
                        break;
                case 5:
                        msg = HIM"$N凝神定气，使出七伤拳总诀中的「"HIR"意恍惚诀"HIM"」，向$n送出一股横出之力。\n"NOR;
                        break;
                case 6:
                        msg = HIR"$N大喝一声，须发俱张，使出「七伤总诀」，左右双拳连续击出，威猛无俦，打向$n。\n"NOR;
                        break;
                }
                msg += HIW"$n只觉得$N这一拳之中共有七股不同劲力，变幻百端，犹豫间已被这股力道笼罩全身，顿时身受严重的内伤。\n" NOR;  
                result += ([ "msg" : msg ]);
                return result;       
        }
}

void skill_improved(object me)
{
        object *ob;
        int i, skill;
        skill = me->query_skill("qishang-quan", 1);
        
        if (me->query("max_neili") < skill * 15 && skill < 200)
        {
                switch(random(5)){
                case 0 : 
                        tell_object(me, HIR"你肩头云门穴突然一阵轻微隐痛，是肺脉伤了！\n"NOR);
                        me->add("max_neili", -random(100));
                        break;      
                case 1 : 
                        tell_object(me, HIR"你腿上无里穴突然酸痛难当，是肝脉伤了！\n"NOR);
                        me->add("combat_exp", -random(7000));
                        break;
                case 2 : 
                        message_vision(HIR"$N心脉练伤，突然狂性大发、无法抑制了！\n"NOR, me);
                        me->set_skill("qishang-quan", skill - 1);
                        break;
                case 3 : 
                        tell_object(me, HIR"你上臂青灵穴突然一时麻痒难当，是心脉伤了！\n"NOR);
                        me->add("max_neili", -random(100));
                        break;
                case 4 : 
                        tell_object(me, HIR"你突然觉得体内阴阳二气串行金木水火土五行，无法抑制了！\n"NOR);
                        me->set_skill("qishang-quan", skill-2);
                        break;
                }
                // me->unconcious();
        }
}
