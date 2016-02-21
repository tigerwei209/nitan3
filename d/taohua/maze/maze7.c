// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

#include "maze.h"

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ����ԼĪ���˶�ߵĴ�ʯ�鹹�ɵ���ʯ�󣬹�ģ�ƺ����󣬵�
̧����ȥ�����ܾ������ص�������Ᾱ�ʯ����ȫ��������·ͨ��ʯ��֮�⣬
��֮���г�������������������������ͷ����ʯ������һ��б����ʯ��(s
hibei)�������ڸ����С�
LONG );

	set("exits", ([
		"east"  : __DIR__"maze36",
		"west"  : __DIR__"maze46",
		"north" : __DIR__"maze4",
	]));

	set("item_desc", ([
	        "shibei" : "
����ʦ���꣬���ˣ����޾̡�
����������ʦ�����ɣ�����ס�
�����Ŷ�����ʦ�У����޾̣�����������
����������ʦ����ʬ���ס�
�������ģ�ʦ��Σ��޾̡�
�������壺�����ݣ���ִ�ԣ��޾̡�����˧ʦ��������ʬ�����ס�
������������������������мң�С�����á�
\n",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
	
	me->add_temp("taohua/count", 7);
	check_count(me, 7);
	return;
}