// Room: /d/gaochang/room75.c
// by mei

inherit ROOM;

void create()
{
        set("short", "雪谷");
        set("long", @LONG
这里三面是高高耸立的险峰，四周是深可及膝的积雪。
LONG );

        set("exits", ([ 
                "out" : __DIR__"kunlun6",
        ]));

        if (random(10) > 5)
                set("objects", ([ 
                        __DIR__"obj/xuecan" : 1,
                        __DIR__"obj/xueshen" : 1,
                ]));

        setup();
}
void init()
{
        add_action("do_prize", "prize");
        add_action("do_chip", "chip");
}
int do_chip(string arg)
{
        object weapon, me = this_player();
        int power;
        
        if (! arg || arg != "冰")   
                return 0;
        
        if (! query("hanyu") || query("chip"))    
                return notify_fail("冰块已经被人凿开了。\n");
                
        weapon = me->query_temp("weapon");
        if (! weapon)    
                return notify_fail("空手恐怕不能把冰敲开吧？\n");
                
        power = weapon->query("weapon_prop/damage") + 
                me->query_str()+weapon->query_weight() / 1000;
                
        set("chip", 1);
        
        switch (weapon->query("skill_type"))
        {
        case "sword":
                if (power > 1200)
                {
                        message_vision("$N用手中的"+weapon->name()+"使劲往冰上凿去。\n",me);
                        message_vision("冰块一下被$N凿开了，一股绿光直冲天际。\n",me); 
                        message("vision","冰块下露出一块绿光晶莹的千年寒玉。\n", this_object()); 
                        return 1;
                }        
                break;
        case "blade":
                if (power > 1000)
                {
                        message_vision("$N用手中的" + weapon->name() + "使劲往冰上劈去。\n", me);
                        message_vision("冰块一下被$N凿开了，一股绿光直冲天际。\n", me); 
                        message("vision", "冰块下露出一块绿光晶莹的千年寒玉。\n", this_object()); 
                        return 1;
                }        
                break;
        case "dagger":
                if (power > 1800){
                        message_vision("$N用手中的"+weapon->name()+"使劲往冰上凿去。\n",me);
                        message_vision("冰块一下被$N凿开了，一股绿光直冲天际。\n",me); 
                        message("vision","冰块下露出一块绿光晶莹的千年寒玉。\n",this_object()); 
                        return 1;
                }
                break;
        case "whip":
                if (power > 2000){
                        message_vision("$N用手中的"+weapon->name()+"使劲往冰上挥去。\n",me);
                        message_vision("冰块一下被$N凿开了，一股绿光直冲天际。\n",me); 
                        message("vision","冰块下露出一块绿光晶莹的千年寒玉。\n",this_object()); 
                        return 1;
                }        
                break;
        case "chui":
        case "hammer":
                if (power > 800){
                        message_vision("$N用手中的"+weapon->name()+"使劲往冰上砸去。\n",me);
                        message_vision("冰块一下被$N凿开了，一股绿光直冲天际。\n",me); 
                        message("vision","冰块下露出一块绿光晶莹的千年寒玉。\n",this_object()); 
                        return 1;
                }        
                break;
        case "staff":
        case "club":
                if (power > 1500){
                        message_vision("$N用手中的"+weapon->name()+"使劲往冰上敲去。\n",me);
                        message_vision("冰块一下被$N凿开了，一股绿光直冲天际。\n",me); 
                        message("vision","冰块下露出一块绿光晶莹的千年寒玉。\n",this_object()); 
                        return 1;
                }        
                break;
        default:    
                message_vision("冰块一下就被$N砸个粉碎。\n",me);
                set("hanyu",0);
                set("chip",1);
                return 1;
        }
        set("chip",0);
        message_vision("$N用手中的"+weapon->name()+"使劲往冰上凿去。\n",me);
        message("vision","但冰块却巍然不动。\n",this_object());
        return 1;
}
int do_prize(string arg)
{
        object ob, me = this_player();
    
        if (!arg || arg!="寒玉")   return 0;
        if (!query("hanyu") || !query("chip")) return 0;
        ob=new(__DIR__"obj/hanyu");
        ob->move(me);
        set("hanyu",0);
        delete("item_desc");
        message_vision("$N高兴地把寒玉从冰里挖了出来。\n",me);
        return 1;
}
void reset()
{
        ::reset();
        set("hanyu",1);
        set("chip",0);
        set("item_desc", ([
                "积雪" : "    在积雪的中央，有处地方结了很厚的一层冰。\n冰带点绿色，真想凿(chip)开看看。\n", 
        ])); 
}

