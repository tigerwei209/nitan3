//Room: qunyulou1.c

inherit ROOM;

void create()
{
        set("short", "群玉楼大厅");
        set("long", @LONG
群玉楼大厅。三面都糊着纱窗，窗棂纵横交错，分成大小格式的花纹，每一
格都有一方小玻璃镶嵌着，显得甚为雅致，玻璃内灯光流映生辉，案头所供养的
梅花，疏影横斜，也贴在玻璃窗上。炫目的朝阳从琉璃窗格透入，微风轻拂，缕
缕幽香，沁人心脾。
LONG );
        set("exits", ([ /* sizeof() == 2 */
        	"north" : "/d/changan/qunyulou",
        	"up"   : "/d/changan/qunyulou2",
        ]));
        set("objects", ([
        	"/d/changan/npc/lingfeixue" : 1,
        ]) );

	set("coor/x", -390);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
