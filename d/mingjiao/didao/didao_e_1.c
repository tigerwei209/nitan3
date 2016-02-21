// Code of ShenZhou
// Room: didao_e.c �ص���
// Zhangchi 3/00

inherit ROOM;
#include "didao.h"

void create()
{
	set("short", "�ص�");
	set("long", @LONG
����һ���ո��ڳɵĵص������������������졣
LONG
	);
	set("exits", ([
		"west": "/d/mingjiao/didao/didao_e",
]));
	
	set("cost", 1);
	set("valid_dig","east");

	setup();
//	replace_program(ROOM);
}

void init()
{
	int num=get_room("east");
	if (num >= 2)
		set("exits/east","/d/mingjiao/didao/didao_e_2");
	else
		delete("exits/east");

	add_action("do_dig","wa");
	add_action("do_dig","dig");
}
