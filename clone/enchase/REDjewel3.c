#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(RED "稀世宝石" NOR, ({ "RED jewel3","jewel3" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", RED "一颗红光闪闪的精美宝石，给人以不同寻常的感觉。\n" NOR);
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


                        "str" : 3,           // 增加膂力
                        "dex" : 3,           // 增加根骨

                        ////////////////////     兵器特有属性

                        "attack" : 30,        // 攻击等级：+30
                        "damage" : 30,        // 兵器伤害：+30
                        "fire_attack"   : 30, // 火焰攻击
                        "perferm_ap"    : 3,   // 绝招命中：+3%
                        "add_damage"    : 2, // 追加伤害2%

                   ]));

                set("enchase/aspe_data",       // 防具上附加属性汇总
                   ([
                        ////////////////////     兵防共有属性

                        "str" : 3,            // 增加膂力
                        "dex" : 3,            // 增加根骨
                        ////////////////////     防具特有属性

                        "reduce_fire"   : 20, // 化解火焰：20%
                        "reduce_damage" : 20, // 化解伤害：20%
                        "max_neili"     : 6, // 内力上限：+6%
                        "perform_dp"    : 2,  // 绝招防御：+2%

                        "qi_recover_speed"     : 8, // 气血恢复速度：+8%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


