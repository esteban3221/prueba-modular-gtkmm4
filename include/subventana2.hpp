#pragma once
#include <gtkmm.h>

class subventana2: public Gtk::Window
{
private:
    /* data */
    Gtk::Box *box_subventana2 = nullptr;
    bool on_window_delete_event();
    Gtk::ProgressBar *pg_bar;
    Gtk::ToggleButton *btn_tgl_pg;

    sigc::connection m_connection_timeout;

    bool on_timeout();
    void on_checkbutton_activity();

public:
    subventana2(/* args */);
    ~subventana2();
};
