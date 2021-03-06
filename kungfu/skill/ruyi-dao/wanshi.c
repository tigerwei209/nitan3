// ruyi.c 万事如意

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, ap, dp, level, damage;
 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("「万事如意」只能对战斗中的对手使用。\n");
 
        if (!objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("刀都没有，使什么「万事如意」？\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("你的真气不够！\n");

        if ((int)me->query_skill("xiaowuxiang", 1) < 100
                && (int)me->query_skill("lingjiu-xinfa", 1) < 100
                && (int)me->query_skill("xiaoyao-xinfa", 1) < 100
                && (int)me->query_skill("bahuang-gong", 1) < 100
                && (int)me->query_skill("beiming-shengong", 1) < 100)
                return notify_fail("你的所用内功心法不正确，或者功力不够，不能使用万事如意！\n");

        if ( me->query_skill_mapped("force") != "xiaowuxiang"
                && me->query_skill_mapped("force") != "bahuang-gong"
                && me->query_skill_mapped("force") != "lingjiu-xinfa"
                && me->query_skill_mapped("force") != "xiaoyao-xinfa"
                && me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("你没有运用逍遥派系列内功！\n");     

        if (me->query_skill("blade") < 100)
                return notify_fail("你的如意刀法还不到家，无法使用「万事如意」！\n");

        if (me->query_skill_mapped("blade") != "ruyi-dao")
                return notify_fail("你没有激发如意刀法，无法使用「完事如意」！\n");

        msg = HIC "$N" HIC "抽身长笑，随手挥出" + weapon->query("name") + HIC "，只见刀光流转，刀气纵横无孔不如，直将$n整个笼罩进去！\n" NOR;
        message_combatd(msg, me, target);

        level = me->query_skill("blade");
        ap = level + me->query_skill("force");
        dp = target->query_skill("parry") + target->query_skill("force");
        if (ap/2 + random(ap) > dp || !living(target))
        {
                me->add("neili", -level);
                damage = me->query_skill("ruyi-dao",1) + me->query("jiali") + me->query_str()*10;
                if (me->query_skill_mapped("force") == "xiaowuxiang") damage += me->query_skill("xiaowuxiang",1);
                if (me->query_skill_mapped("force") == "beiming-shengong" && target->query("neili") > me->query_skill("force") * 2)
                        target->add("neili",-100);
                damage += random(damage);
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 50,
                        HIR "$p" HIR "眼见着刀光飞泄过来却手足无措，结果被$P"
                        HIR "一刀正中胸口，闷哼一声，鲜血飞溅而出！\n" NOR);
                me->start_busy(2);
                target->start_busy(1+random(2));
        }
        else
        {
                msg = HIY "$p" HIY "眼见着刀光飞泄过来，慌忙间就地一个打滚，总算避开了$P"
                      HIY "这招万事如意！\n" NOR;
                me->start_busy(3 + random(3));
        }
        message_combatd(msg, me, target);
        return 1;
}

