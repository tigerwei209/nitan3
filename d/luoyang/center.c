inherit ROOM;

void create()
{
	set("short", "�������Ĺ㳡");
	set("long", @LONG
�����վ�ľ��Ǻպ������ĹŶ���������Ȼ��������������ս���ֻģ�
������������˿��������������ķ�����һ�������������Ĵ��������
��������Ⱥ�����ֵļ��У����չʾ����������ϵĳ��е�������������
��������۹��������οͣ�����������ǵ��Ǵ������������������ʺ���
����һ��ɲ�����°ɣ���Ȼ��������������й�Ҳ������𴦵Ĺ�Ա����
Ĥ�ݵĵط����������ҵĴ�������������������������ʿ�İݷá��㳡
�Ϻ���ո��¹��꣬���������£�����ʪ�����ģ������㳡���˵ĸо���
�ǹ��϶����������������������ųǵ�һ����Ӱ��
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
  		"east" : __DIR__"eroad1",
  		"north" : __DIR__"nroad1",
  		"south" : __DIR__"sroad1",
  		"west" : __DIR__"wroad1",
	]));
        set("objects", ([
                "/d/taishan/npc/jian-ke" : 1,
                "/d/beijing/npc/maiyi2" : 1,
                "/d/beijing/npc/girl4" : 1,
                "/d/beijing/npc/old1" : 1,
                "/clone/npc/walker" : 1,
        ]));
	set("coor/x", -170);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}