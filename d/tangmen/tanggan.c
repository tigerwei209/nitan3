//tanggan.c		�Ĵ����š��Ƹ�����

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long",
"����һ���ª�����ҡ�����ֻ��һ��Ӳľ����һ����ľ����������ס\n"
"������̫̫�����������ƸС�\n"
);
	set("exits", ([
                "west" : __DIR__"nzlang2",
	]));
	set("area", "����");
        set("objects", ([
                "/d/tangmen/npc/tanggan" : 1,
        ]));
	setup();
	replace_program(ROOM);
}