// fish.c 西湖醋鱼
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

int decayed = 0;
void create()
{
        set_name(RED"西湖醋鱼"NOR, ({"fish"}));
        set_weight(1300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘清甜可人的西湖醋鱼，用西湖中的金色鲤鱼
烧制而成，是西湖第一名菜。\n");
                set("unit", "碗");
                set("value", 120);
                set("food_remaining", 20);
                set("food_supply", 20);
        }
}
void decay(int phase) 
{
        string msg;
        object env;
        env = environment();
        decayed = phase;
        set("on_fulan",1);
        set("value",0);
        set("food_remaining",0);
        switch(phase)
        {
                case 1:
                        msg =  name(1) + "开始变质了，发出一股难闻的馊味。\n";
                        set("old_name",name(1));
                        set_name("变质的" + query("old_name"),({ query("id") }));
                        call_out("decay", 120, phase + 1);
                        break;
                case 2:
                        msg = name(1) + "开始腐烂了，上面长出许多绿毛，发出难闻的臭味。\n";
                        set_name("腐烂的" + query("old_name"),({ query("id") }));
                        call_out("decay", 60, phase + 1);
                        break;
                case 3:
                        msg = "一阵风吹过，把" + name(1) + "化成灰吹散了。\n";
                        if( env )
                                all_inventory(this_object())->move(env);
                        tell_room(env, msg);
                        destruct(this_object());
                        return;
        }
        while (env && env->is_character())
                env = environment(env);
        if (env) tell_room(env, msg); 
}
