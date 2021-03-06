// This is player's own perform (Write by Lonely@nt2)
// Create by 段左助(Rare) at Sat Apr  8 14:21:59 2006
// 十二剑气(mys)

#include <ansi.h>
#include <combat.h>

#define PFM "「" HIW "十二剑气" NOR "」"

inherit F_SSERVER;
#include <balance.h>

string *weapon_sk = ({
        "sword", "blade", "staff", "whip", "club", "hammer", "axe"
});

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int count;
        int i, attack_time;

        if (! me->query("can_perform/" + "six-finger" + "/" + "mys"))
                return notify_fail("你还没有受到高手指点，还不会运用" PFM "。\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(PFM "只能对战斗中的对手使用。\n");

        if (member_array("finger", weapon_sk) != -1)
        {
                if (! objectp(weapon = me->query_temp("weapon"))
                   || (string)weapon->query("skill_type") != "finger")
                        return notify_fail("你所使用的武器不对，难以施展" PFM "。\n");
        } else
        {
                if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        return notify_fail(PFM "只能空手使用。\n");             
        }
        
        if ((int)me->query_skill("six-finger", 1) < 400)
                return notify_fail("你" + to_chinese("six-finger") + "不够娴熟，难以施展" PFM "。\n");

        if (member_array("finger", weapon_sk) == -1)
        {
                if (me->query_skill_prepared("finger") != "six-finger")
                        return notify_fail("你没有准备" + to_chinese("six-finger") + "，难以施展" PFM "。\n");
        }
        
        if (me->query("neili") < 300)
                return notify_fail("你现在的真气不够，难以施展" PFM "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N摊开双手，手指连弹，霎时间空气炙热，几欲沸腾，六道剑气分自六穴，一起杀向$n！转眼间却又见$N双手支地，双脚伸出，竟又是六道剑气由足上六穴喷涌而出！" + "\n" + NOR;

        ap = ap_power(me, "finger");
        dp = dp_power(target, "dodge");
        attack_time = 6;

        if (ap * 2 / 3 + random(ap * 2) > dp)
        {
                msg += HIM "$n久闯江湖，六脉神剑也识得二三，但何曾见过如此神妙之用法，一愣神之间先机已失，只得任人宰割。霎时无数剑气穿身而出，全身上下无数血洞，鲜血狂喷不止，真气涣散之下，奄奄一息。" + "\n" NOR;
                count = ap / 10;
                me->add_temp("apply/attack", count);
                me->add_temp("apply/damage", count);
        } else
        {
                msg += NOR + CYN "$p哪曾见过六脉神剑如此用法，心道必死无疑，当即双眼一闭，仰头便倒，昏倒在地，却恰好避过来招。" + "\n" NOR;
                count = 0;
        }

        message_sort(msg, me, target);

        attack_time += me->query("jieti/times") * 2;
        if (attack_time > 13)
                attack_time = 13;

        me->add("neili", -attack_time * 20);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(2) && ! target->is_busy()) target->start_busy(1);

                COMBAT_D->do_attack(me, target, (member_array("finger", weapon_sk) == -1 ? 0 : weapon), 0);
        }
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -count);
        me->start_busy(3 + random(attack_time/ 3));

        return 1;
}

