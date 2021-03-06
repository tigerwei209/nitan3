#include <room.h>
inherit ROOM;

void create()
{
	set("short", "地西大街");
        set("long", @LONG
这里是北京城地安门的西街。街道是整整齐齐的杨树林，道上行人络绎不绝，
车辆马匹穿插其中。大街上有闲逛的游人，上京赶考的考生，背负着担子的挑夫
以及正在玩耍着的幼童构出了一幅繁忙热闹的盛世景象。北边是京城里最大的钱
庄，南边是地安门的西街广场。
LONG );
       set("exits", ([
		"north" : "/d/beijing/qianzhuang",
		"south" : "/d/beijing/di_xigc",
		"east" : "/d/beijing/di_dajie1",
		"west" : "/d/beijing/di_4",
	]));

	set("outdoors", "beijing");
	set("coor/x", -40);
	set("coor/y", 320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
