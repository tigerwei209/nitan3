#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(YEL "稀世宝石" NOR, ({ "YEL jewel3","jewel3" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "一颗黄光闪闪的精美宝石，给人以不同寻常的感觉。\n" NOR);
                set("unit", "块");
                set("value", 120000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "戴在头上。\n" NOR);
                set("remove_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "从头上摘了下来。\n" NOR);
                    
                set("enchase/type", "all");   // 可镶嵌的道具类型"all"或"sword"或"blade"或"cloth"等
                set("enchase/cur_firm", 90);  // 抗磨损度
                set("enchase/wspe_data",      // 兵器上附加属性汇总
                   ([
                        ////////////////////     兵防共有属性


                        "con" : 3,           // 增加身法

                        ////////////////////     兵器特有属性

                        "busy_time"     : 2,  // 忙乱敌人1秒
                        "unarmed_damage": 30, // 手法伤害：+20
                        "no_exert"      : 2,  // 内息紊乱1秒

                   ]));

                set("enchase/aspe_data",       // 防具上附加属性汇总
                   ([
                        ////////////////////     兵防共有属性

                        "con" : 3,           // 增加身法

                        ////////////////////     防具特有属性

                        "avoid_poison"  : 30, // 毒性回避：30%
                        "dodge"  : 30,       // 轻功等级：+30
                        "reduce_busy"   : 20, // 化解忙乱：20%

                        "jingli_recover_speed" : 7, // 精力恢复速度：+7%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


