#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�ٱ�", ({ "guan bing", "guan", "bing" }));
        set("age", 22);
        set("gender", "����");
        set("long", "���Ǹ����߶�����ϱ�����Ͳ�С�ˣ�����δ�ɼҡ�\n");
        set("attitude", "peaceful");

        set("str", 24);
        set("dex", 16);
        set("combat_exp", 10000);
        set("shen_type", 1);

        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("blade", 40);
        set_skill("force", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                CYN "�ٱ��ȵ����󵨵��񣬾����췴���ɣ�\n" NOR,
                CYN "�ٱ��ȵ����ܵ��˺����ܲ��������㻹�ǿ�����־��ܣ�\n" NOR,
        }));
        setup();
        carry_object("/clone/weapon/blade")->wield();
        carry_object("/clone/cloth/junfu")->wear();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && 
                (int)ob->query_condition("killer"))
        {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}

int accept_fight(object me)
{
        command("say ��ү����������ɱ�ţ��������㵹ù��\n");
        kill_ob(me);
        return 1;
}