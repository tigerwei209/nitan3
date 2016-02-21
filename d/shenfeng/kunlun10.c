
inherit ROOM;
void create()
{
        set("short", "翠谷");
        set("long", @LONG
面前竟是个花团锦簇的翠谷，红花绿树，交相掩映。放眼四望，但见
翠谷四周高山环绕，似乎亘古以来从未有人迹到过。四面雪峰插云，险峻
陡峭，决计无法攀援出入。
LONG );
        set("objects", ([ 
                __DIR__"npc/monkey" : 2,
        ]));
        set("exits", ([ 
                "west" : __DIR__"kunlun11",
                "north" : __DIR__"kunlun12",
        ]));
        set("outdoors", "kunlun");
        setup();
        replace_program(ROOM);
}
