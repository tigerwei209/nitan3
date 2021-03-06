// throwing.c

#include <weapon.h>

inherit COMBINED_ITEM;
inherit F_EQUIP;

varargs void init_throwing(int damage, int flag)
{
	if (clonep(this_object())) return;

	set("weapon_prop/damage", damage);
	set("flag", POINTED);
}

void setup()
{
	if (clonep(this_object())) return;

        set("no_wield", "暗器不是用来装备的。\n");
	set("skill_type", "throwing");
        set("consistence", 100);
	if (! query("actions"))
        {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "throw" }) );
                set("stable", 0);
	}
}

string extra_long()
{
        string str;
        
        str =  "物品类型    ：    兵器\n";
        str += "属    性    ：    暗器\n";
        str += sprintf("攻    击    ：    %d\n", query("weapon_prop/damage"));
        str += sprintf("重    量    ：    %d\n", this_object()->query_weight());
        str += sprintf("杀    戮    ：    %d\n", query("combat/PKS"));
        str += sprintf("使用方式    ：    输入指令 hand %s 装备。\n", query("id"));
        str += sprintf("                  输入指令 hand none 卸下。\n", query("id"));
        if (this_object()->query_autoload())
                str += "下线丢失    ：    否\n";
        else
                str += "下线丢失    ：    是\n";
        return str;
}
