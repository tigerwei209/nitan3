inherit ITEM;

void create()
{
        set_name("����", ({ "kite" }) );
        set_weight(150);
        set_max_encumbrance(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("prep", "on");
                set("long", "һ���������ݣ��ŷ��ݵ����ϰ���һ��СС�����ڡ� \n");
                set("value", 2000);
        }
}

void init()
{
        add_action("do_play", "play");
}

int do_play(string arg)
{
   object me, ob;    

   me = this_player();
   ob = this_object();
   if( me->is_fighting() )
      return notify_fail("��ս���зŷ��ݣ���������\n");
   if( me->is_busy() )
      return notify_fail("����һ��������û����ɣ����ܷŷ��ݡ�\n");
   if (!arg || (arg != "kite" && arg != "����")) return 0;
   tell_object(me, "���ͳ�һ��" + ob->name() + "��\n");
   environment(me)->kite_notify(ob, 0);

   return 1;
}

int is_container() { return 1; }
