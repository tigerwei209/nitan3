// feilaifeng.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "飞来峰");
        set("long", @LONG
飞来峰又名灵鹫峰。延着盘山小道往上走，只见溪盘岩石壁间雕着一尊袒腹
露胸，喜笑自若的弭勒佛。旁边是一座气魄胸伟的多闻天王。北边是下山的路。
小路往上延伸向东西两边。
LONG );
        set("exits", ([
                "north"     : "/d/hangzhou/road1",
                "eastup"    : "/d/hangzhou/qinglindong",
                "westup"    : "/d/hangzhou/longhongdong",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
