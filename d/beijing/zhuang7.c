#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "庄府大厅");
        set("long", @LONG
这是一间灵堂，堂上供了七八个牌位。看来一座灵堂上供的是一家死人。
LONG );
    set("exits", ([
	"east" : "/d/beijing/zhuang5",
    ]));
    set("objects", ([
	"/d/shenlong/npc/dizi": 1,
    ]));
    set("outdoors", "beijing");
    setup();
    replace_program(ROOM); 
}
