// head.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	if (! clonep(this_object()))
                set("armor_type", TYPE_FINGER);

        ::setup();
}
string extra_long() 
{ 

        string str; 

        str =  "物品类型    ：    防具\n"; 
        str += "属    性    ：    指套\n"; 
        str += sprintf("防    护    ：    %d\n", query("armor_prop/armor")); 
       str += sprintf("重    量    ：    %d\n", this_object()->query_weight());
        str += sprintf("使用方式    ：    输入指令 wear %s 装备。\n", query("id")); 
        str += sprintf("                  输入指令 remove %s 卸下。\n", query("id")); 
        if (this_object()->query_autoload()) 
                 str += "下线丢失    ：    否\n"; 
            else 
                       str += "下线丢失    ：    是\n"; 
        return str; 
 }
