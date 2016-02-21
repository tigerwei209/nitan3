// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define JU "��" HIR "��Ѫצ" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/yingzhua-shou/xue"))
                return notify_fail("�㻹û���ܹ�����ָ�㣬�޷�ʩչ" JU "��\n"); 

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(JU "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("yingzhua-shou", 1) < 60)
                return notify_fail("���ѹ�ӥצ��������죬����ʩչ" JU "��\n");

        if (me->query_skill_mapped("claw") != "yingzhua-shou")
                return notify_fail("��û�м����ѹ�ӥצ��������ʩչ" JU "��\n");

        if (me->query_skill_prepared("claw") != "yingzhua-shou")
                return notify_fail("��û��׼�����ѹ�ӥצ��������ʩչ" JU "��\n");

        if (me->query_skill("force") < 80)
                return notify_fail("����ڹ���Ϊ����������ʩչ" JU "��\n");

        if ((int)me->query("neili") < 220)
                return notify_fail("�����ڵ���������������ʩչ" JU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = ap_power(me, "claw");
        dp = dp_power(target, "parry");

        msg = HIW "\n$N" HIW "��ת������˫�ֺ���צ�У�ʩ�����С�" HIR "��"
              "Ѫצ" HIW "����Ѹ���ޱȵ�ץ��$n" HIW "��\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                damage = da_power(me, "claw");
                
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 55,
                                           HIR "����$N" HIR "˫צ������$n" HIR "�����ܲ������ؿڱ�$N" HIR
                                           "ץ��ʮ��Ѫ�ۡ�\n" NOR);

                me->start_busy(3);
                me->add("neili", -200);
        } else
        {
                msg += CYN "$n" CYN "�����мܣ�����$N" CYN "���л��⡣\n" NOR;

                me->start_busy(4);
                me->add("neili", -100);
        }
        message_sort(msg, me, target);
        return 1;
}


