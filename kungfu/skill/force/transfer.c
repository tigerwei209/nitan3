// transfer.c 转内力
// Modified by Venus Oct.1997
#include <ansi.h>

int exert(object me, object target)
{
    int force, trans;

        if (! me->query("breakup")) 
                return notify_fail("你还没有领悟传送真气的诀窍。\n"); 

    if( query_ip_name(target)==query_ip_name(me))
       return notify_fail("你要将真气传给谁？\n");

    if( !target || target==me || !living(target) )
       return notify_fail("你要将真气传给哪位？\n");

    if( me->query_skill_mapped("force") != target->query_skill_mapped("force") )
       return notify_fail(target->name()+"所使用的内功和你不同，不能传内力。\n");

    if( (int)me->query("neili") <= (int)me->query("max_neili")/3 )
       return notify_fail("你的真气不足。\n");

    if( (int)me->query("max_neili") <= (int)target->query("max_neili") )
       return notify_fail("你的真气还不如人家多，传不过去。\n");

    if ((int)target->query("neili")>=(int)target->query("max_neili")*4)
       return notify_fail("对方的真气充沛，不需要你的真气。\n");

    force = me->query("neili") - (me->query("max_neili")/3);

    if( force/2 < 1 ) return notify_fail("你的真气不足。\n");
    me->add("neili", -force/3 );
    if( (int)me->query("max_neili") <= (int)target->query("max_neili")*5/4 )
       me->add("max_neili", -1);

    message_combatd(HIW"$N一掌拍在$n背心，顺势运气将体内真气传送过去。\n"NOR, me,target);
    target->add("neili", force/2);
    write("Ok。\n");
    tell_object(target, HIW "你觉得一股热气从"+me->name()+"的手掌中传了过来。\n" NOR);
    return 1;
}

