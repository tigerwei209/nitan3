//Room: qunyuys5.c

inherit ROOM;

void create()
{
        set("short", "群玉楼雅室");
        set("long", @LONG
一间雅室。房中放着一张大床，床上铺着绣花的锦被和枕头。湘绣驰名天下，
大红锦被上绣的是一对戏水鸳鸯，颜色灿烂，栩栩欲活。几上点着一根红烛，红
烛旁是一面明镜，一只梳妆箱子。床前地下两对绣花拖鞋，一对男的，一对女的，
并排而置。
LONG );
        set("exits", ([ /* sizeof() == 1 */
        	"south" : "/d/changan/qunyulou3",
        ]));
        set("objects", ([
        	"/d/changan/npc/baiyi" : 1,
        ]) );

	set("coor/x", -390);
	set("coor/y", 30);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
