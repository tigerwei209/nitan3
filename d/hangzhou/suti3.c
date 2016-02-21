// suti3.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "苏堤");
        set("long", @LONG
寒冬，瑞雪霏霏中，不少游人踏雪观景。从堤上极目远眺，只见四周玉树琼
林。北边是东浦桥，南面是压堤桥。
LONG );
        set("exits", ([
            "north"     : "/d/hangzhou/suti2",
            "south"     : "/d/hangzhou/suti4",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
