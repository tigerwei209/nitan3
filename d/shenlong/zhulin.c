#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "竹林");
        set("long", @LONG
这里是一片青竹林,一阵凉风吹过,竹叶沙沙作响,东边是大厅,西边是教主的
居室.
LONG );

    set("exits", ([
	"east" : __DIR__"dating",
	"west" : __DIR__"jushi",
    ]));
    set("outdoors", "shenlong");
    setup();
}

