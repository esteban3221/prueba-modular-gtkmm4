#pragma once
#include <gtkmm.h>

class subventana1: public Gtk::Window
{
private:
    /* data */
    Gtk::Box *box_subventana1 = nullptr;
    Gtk::Button *btn_message= nullptr;

    std::unique_ptr<Gtk::MessageDialog> m_pDialog;

    void on_btn_message_clicked();

public:
    subventana1(/* args */);
    ~subventana1();
};

