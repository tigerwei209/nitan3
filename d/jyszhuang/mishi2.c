// by Lonely

inherit ROOM;

int do_study(string arg);

void create()
{
        set("short", "地下室");
        set("long", @LONG
这里是宫殿底下的地下密室。密室虽小，却也五脏俱全，
石桌石椅，石几石床，连室内放的几件器皿，也都是石制的。
看来似乎很久以前有人在这里住过。正中的石桌(table)上平
放着一块薄薄的石板，上面好象刻着些什么。
LONG
        );
        set("exits", ([
                "up" : __DIR__"mishi1",
                "south" : __DIR__"shanzhuang",
        ]) );
        set("objects", ([
        ]) );

        set("no_fight", 1);
        set("item_desc", ([
                "table" : "这是一整块巨石雕成的石桌，上面刻了些奇怪的图形。\n",
        ]));

        setup();
}

void init()
{
        add_action("do_study", "study");
}


int do_study(string arg)
{
        object me;
        int    jing_cost;

        me = this_player();

        if ( !arg || ( arg != "table" ) )
                return notify_fail("什么？\n");

       if (me->is_busy()) return notify_fail("你正在忙着呢！\n");

        if ( (int)me->query_skill("literate", 1) < 1)
                return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

        jing_cost = (-1) * random(2);
        if((int)me->query("jing") < jing_cost)
                return notify_fail("你现在精神无法集中！\n");

        me->add("jing", jing_cost);

        tell_object(me, "你开始专心研读石桌上的古怪图形。\n");
        if ( (int)me->query_skill("martial-cognize", 1) < 500)
        {
                me->improve_skill("martial-cognize", me->query_int() * 10);
                tell_object(me, "你对着石桌琢磨了一回儿，似乎对武学修养有点长进。\n");
        } else
        {
                me->improve_skill("martial-cognize", me->query_int() * 5);
                tell_object(me, "你对着石桌琢磨了一回儿，似乎对武学修养稍微有点长进。\n");
        }
        me->start_busy(random(2));
        return 1;
}

int valid_leave(object me, string dir)
{
        if (dir == "up" && ! wizardp(me))
                return notify_fail("\n突然之间，前面一个阴森森的声音喝道：
「我在这里已安安静静的住了一千年，谁也不敢来打扰我。那一个大胆过来，立刻就死！」\n
你只觉得心头一寒，脚下直哆嗦，再也往前走不了一步。\n ");
        return 1;
}

