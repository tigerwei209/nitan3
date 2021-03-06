// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <room.h>

inherit BUILD_ROOM;
string look_shu();

void create()
{
        set("short", HIY "名人堂" NOR);
        set("long",
"这里就是泥潭的名人堂。在这里供奉的有大侠，也有魔头，也有不是\n"
"大侠不是魔头的玩家。无论是哪一位，都曾冠绝一时，都有一个长长而惊\n"
"心动魄的故事，每一个故事都曾很深远地影响了一代甚至两三代玩家。虽\n"
"然他们都曾经轰轰烈烈掀起满江湖的风雨，如今，他们再也不会在江湖出\n"
"现了。他们都已经退出江湖，但他们的侠影魔踪很长时间以后仍是一个传\n"
"说。\n"
);

        set("no_fight", "1");
        set("no_steal", "1");
        set("no_beg", "1");
        set("no_sleep_room", "1");
        set("no_clean_up", 0);

        set("exits", ([
                "down" : __DIR__"wumiao2",
        ]));
        set("objects", ([
                // __DIR__"npc/mingren/gzf" : 1,
        ]));
	set("coor/x", -10);
	set("coor/y", 20);
	set("coor/z", 20);
	setup();
}

