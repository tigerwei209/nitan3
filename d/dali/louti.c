//Room: /d/dali/louti.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","楼梯");
        set("long", @LONG
这就是通往二楼『迎宾斋』的楼梯，楼梯高有五十余级，上面铺了鲜红的毛
毡，楼梯两侧站了一些素衣卫士，楼上则是贵宾休息的地方。
LONG );
	set("objects", ([
	   "/d/dali/npc/weishi": 3,
	   CLASS_D("dali")+"/gaoshengtai": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "up"      : "/d/dali/zoulang1",
	    "south"   : "/d/dali/dating",
	]));
	setup();
	replace_program(ROOM);
}

