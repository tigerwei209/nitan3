inherit ROOM;

void create()
{
    set("short", "墓地");
        set("long", @LONG
这里是黑木崖日月神教教众的墓地。墓地周围种了一些矮矮的花树。树上的
白花星星点点。白花中间是一高大的石碑(bei)，整个墓地干干净净，显然天天有
人打扫。
LONG );
	set("exits", ([
            "west"      : "/d/heimuya/grass1",
        ]));
	set("item_desc", ([
            "bei": "上面刻着：神教子民，永生不灭。\n"
	]));
        set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}
