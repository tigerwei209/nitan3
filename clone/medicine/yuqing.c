// yuqing.c  玉清散   by sinb

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIC "玉清散" NOR, ({"yuqing san", "san"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一包玉清散，据说是武当派的秘药，功能强身健体，延年益寿。\n");
                set("base_unit", "包");
                set("base_value", 20000);
                set("base_weight", 80);
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "chaihu"   : 1,
                                    "dangui"   : 1,
                                    "lurong"   : 1,
                                    "xiefen"   : 1,
                                    "honghua"  : 1,
                                    "taoxian"  : 1,
                                    "zzfen"    : 1,
                                    "heshouwu" : 1,
                                    "renshen"  : 1,
                                    "shengdi"  : 1 ]),
                        "neili" : 300,
                        "jing"  : 50,
                        "time"  : 5,
                        "min_level" : 120,
                        "medical" : 200,
                ]));
        }
        setup();
}

int do_effect(object me)
{

        /*
        if (time() - me->query_temp("last_eat/yuqing") < 320)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        me->set_temp("last_eat/yuqing", time());
        */

        message_vision(YEL "$N" YEL "吃下一粒" + name() +
                       YEL "，内息运行一小周天，感觉身体发生了一些变化。\n", me);

        me->add("max_jingli" , 10 + random(2));
        if (me->query("max_jingli") > me->query_current_jingli_limit())
                me->set("max_jingli", me->query_current_jingli_limit());
        // me->start_busy(3);

        add_amount(-1); 
        if (query_amount() < 1) 
                destruct(this_object()); 

        return 1;
}

