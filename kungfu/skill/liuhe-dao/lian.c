// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// lianhuan.c  六合刀之连环诀

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill;

/*
        if (userp(me) && ! me->query("can_perform/liuhe-dao/lian"))
                return notify_fail("你还没有受过高人指点，无法施展连环决。\n");
*/
                
        if (! target ) target = offensive_target(me);

        if (! target
        ||      ! target->is_character()
        ||      ! me->is_fighting(target) )
                return notify_fail("六合刀连环诀只能对战斗中的对手使用。\n");

        if (me->query_temp("lianhuan") )
                return notify_fail("你已在使用六合刀连环诀了！\n");

        weapon = me->query_temp("weapon");
        if (! objectp(weapon) || weapon->query("skill_type") != "blade" )
                return notify_fail("你手中无刀，如何能够施展连环诀？\n");

        if (me->query_skill_mapped("force") != "huntian-qigong" )
                return notify_fail("你所用的并非混天气功，无法配合刀法施展连环诀！\n");

        if (me->query_skill("force") < 100)
                return notify_fail("你的混天气功火候未到，无法配合刀法施展连环诀！\n");

        if (me->query_skill("blade") < 100)
                return notify_fail("你六合刀法修为不足，还不会使用连环诀！\n");

        if (me->query("neili") <= 300)
                return notify_fail("你的内力不够施展连环诀！\n");
                
        skill = me->query_skill("blade");
        
        message_combatd(HIR "\n$N大喝一声，手中刀光霍霍，招招连环，快如电闪！\n\n" NOR, me, target);

        me->set_temp("lianhuan", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/5);
        me->add("neili", -300);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (! objectp(me)) return;
        
        me->delete_temp("lianhuan");
}

