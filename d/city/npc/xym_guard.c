//xym_guard.c 

inherit NPC; 

#include <ansi.h> 

int ask_xym(object me); 
void create() 
{ 
        set_name("����",({"shou wei","guard"}) ); 
        set("long","����һλ����Ӣ�˲����������ˡ�\n"); 
        set("title","�����˽���"); 
        set("gender","����"); 
        set("age",20); 
        set("combat_exp",100); 
        set("inquiry",([ 
                "������" : (: ask_xym :), 
        ]) ); 
        setup(); 
} 

int ask_xym(object me) 
{ 
        me = this_player(); 
     
        if (me->query("bunch/bunch_name") != "������" && (int)me->query("shen") >= 0) 
        { 
                command("famours " + me->query("id")); 
                tell_object(me,"����Ц���еض���˵��������������������˰ɣ�����������\n"); 
                me->set_temp("good_xym", 1); 
                return 1; 
        } 
        if (bad_bunch(me) || (int)me->query("shen") < 0 ) 
        { 
                command("say ��������аħ������Ҵ�ô��\n"); 
                return 1; 
        } 

        tell_object(me, "������������ֵ�����ͬΪ�����ֵܣ���γ����԰�����\n"); 
        return 1; 
} 
