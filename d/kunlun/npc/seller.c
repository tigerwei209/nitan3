inherit KNOWER;
inherit F_VENDOR;

void create()
{
        set_name("С��", ({ "xiao fan", "xiao", "fan" }));
        set("gender", "����" );
        set("age", 32);
        set("long", "���Ǹ�С����������������ʵʵ�������\n"
                    "������Ƕ��ͱ��ˡ�\n");
        set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/xingxiu/obj/fire",
                "/d/quanzhen/npc/obj/stick",
                "/d/quanzhen/npc/obj/bottle",
                "/d/quanzhen/npc/obj/egg",
        }));
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("coin", 100);
}

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy", "buy");
}