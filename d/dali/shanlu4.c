//Room: /d/dali/shanlu4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","山路");
        set("long", @LONG
一条山路，两边是茂密的树林，西面是延绵不绝的大山，道路两旁间或可见
一些夷族的村镇。山路向南蜿蜒着。
LONG );
	set("objects", ([
	   "/d/dali/npc/shennongdizi": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : "/d/dali/shanlu2",
	    "southwest"  : "/d/dali/shanlu5",
	]));
	setup();
	replace_program(ROOM);
}

